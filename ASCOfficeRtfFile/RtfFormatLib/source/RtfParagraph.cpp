﻿/*
 * (c) Copyright Ascensio System SIA 2010-2016
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#include "RtfParagraph.h"
#include "RtfWriter.h"

int RtfParagraph::AddItem( IDocumentElementPtr piRend )
{
	if( TYPE_RTF_CHAR == piRend->GetType() )
	{
		if( m_aArray.size() > 0 && TYPE_RTF_CHAR == m_aArray[ m_aArray.size() - 1 ]->GetType() )//соединяем два текста с одинаковыми свойствами
		{
            RtfCharPtr oCurChar = boost::static_pointer_cast<RtfChar,IDocumentElement>( piRend );
            RtfCharPtr oPrevChar = boost::static_pointer_cast<RtfChar,IDocumentElement>( m_aArray[ m_aArray.size() - 1 ] );
			if( oCurChar->m_oProperty == oPrevChar->m_oProperty )
			{
				oPrevChar->AddText( oCurChar->GetText() );
				return (int)m_aArray.size() - 1;
			}
		}				
	}
	ItemContainer< IDocumentElementPtr >::AddItem( piRend );
	return (int)m_aArray.size() - 1;
}

CString RtfParagraph::RenderToRtf(RenderParameter oRenderParameter)
{
	CString sResult ;
	if( RENDER_TO_RTF_PARAM_CHAR == oRenderParameter.nType )
	{
		for( int i = 0; i < (int)m_aArray.size(); i++ )
		{
			sResult += m_aArray[i]->RenderToRtf( oRenderParameter );
		}
	}
	else
	{
		sResult += L"\\pard\\plain";
		sResult += m_oProperty.RenderToRtf( oRenderParameter ) ;
		
		if( NULL != m_oOldList )
			sResult += m_oOldList->RenderToRtf( oRenderParameter ) ;

		for( int i = 0; i < (int)m_aArray.size(); i++ )
		{
			sResult += m_aArray[i]->RenderToRtf( oRenderParameter );
		}
		
		sResult += m_oProperty.m_oCharProperty.RenderToRtf( oRenderParameter );


		//if( RENDER_TO_RTF_PARAM_NO_PAR != oRenderParameter.nValue )
		//	sResult += T("\\par";
	}
	return sResult;
}

CString RtfParagraph::RenderToOOX(RenderParameter oRenderParameter)
{
	CString sResult ;
	if( RENDER_TO_OOX_PARAM_PLAIN == oRenderParameter.nType )
	{
		for( int i = 0; i < (int)m_aArray.size(); i++ )
		{
			sResult += m_aArray[i]->RenderToOOX(oRenderParameter);
		}
	}
	else if( RENDER_TO_OOX_PARAM_RUN == oRenderParameter.nType )
	{
		for( int i = 0; i < (int)m_aArray.size(); i++ )
		{
			sResult += m_aArray[i]->RenderToOOX(oRenderParameter);
		}
	}
	else if( RENDER_TO_OOX_PARAM_MATH == oRenderParameter.nType )
	{
		if (m_aArray.size() < 1)
		{
			sResult += L"<w:rPr>";
			sResult += m_oProperty.m_oCharProperty.RenderToOOX(oRenderParameter);
			sResult += L"</w:rPr>";
		}
		else
		{
			for( int i = 0; i < (int)m_aArray.size(); i++ )
			{
				sResult += m_aArray[i]->RenderToOOX(oRenderParameter);
			}
		}
	}
	else
	{		
		RenderParameter oNewParam = oRenderParameter;
		oNewParam.nType = RENDER_TO_OOX_PARAM_RUN;
		
		bool bCanConvertToNumbering = false;
		if( NULL != m_oOldList )
			bCanConvertToNumbering = m_oOldList->CanConvertToNumbering();

		sResult += L"<w:p>";
		sResult += L"<w:pPr>";
		
		m_oProperty.m_bOldList = (NULL != m_oOldList);
		sResult += m_oProperty.RenderToOOX(oRenderParameter);

		if( NULL != m_oOldList )
		{
			//для OldList
			if( true == bCanConvertToNumbering )
				sResult += m_oOldList->RenderToOOX( oRenderParameter );
		}
		sResult += L"</w:pPr>";

		if( NULL != m_oOldList )
		{
			//для OldList
			if( false == bCanConvertToNumbering && NULL != m_oOldList->m_oText)
			{
				RtfCharProperty oCharProp = m_oProperty.m_oCharProperty;
				if( NULL != m_oOldList->m_oText )
					oCharProp.m_nFont = m_oOldList->m_oText->m_oProperty.m_oCharProperty.m_nFont;

				oNewParam = oRenderParameter;
				oNewParam.nType = RENDER_TO_OOX_PARAM_TEXT;

				for( int i = 0; i < m_oOldList->m_oText->GetCount(); i++ )
				{
					sResult += L"<w:r>";
					sResult += L"<w:rPr>";
					sResult += oCharProp.RenderToOOX(oRenderParameter);
					sResult += L"</w:rPr>";

					sResult += m_oOldList->m_oText->m_aArray[ i ]->RenderToOOX(oNewParam);
					sResult += L"</w:r>";
				}
			}
		}

		oNewParam.nType = RENDER_TO_OOX_PARAM_RUN;
		
		CString ParagraphContent;
		for( int i = 0; i < m_aArray.size(); i++)
		{
			ParagraphContent += m_aArray[i]->RenderToOOX(oNewParam);
		}

		if (!ParagraphContent.IsEmpty())
			sResult += ParagraphContent;

		sResult += L"</w:p>";
	}
	return sResult;
}


