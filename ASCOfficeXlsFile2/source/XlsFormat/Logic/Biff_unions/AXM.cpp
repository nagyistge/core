#include "precompiled_xls.h"
#include "AXM.h"
#include <Logic/Biff_records/YMult.h>
#include <Logic/Biff_records/StartObject.h>
#include <Logic/Biff_unions/ATTACHEDLABEL.h>
#include <Logic/Biff_records/EndObject.h>

namespace XLS
{;


AXM::AXM()
{
}


AXM::~AXM()
{
}


BaseObjectPtr AXM::clone()
{
	return BaseObjectPtr(new AXM(*this));
}


// AXM = YMult StartObject ATTACHEDLABEL EndObject
const bool AXM::loadContent(BinProcessor& proc)
{
	if(!proc.mandatory<YMult>())
	{
		return false;
	}
	proc.mandatory<StartObject>();
	proc.mandatory<ATTACHEDLABEL>();
	proc.mandatory<EndObject>();

	return true;
}

} // namespace XLS
