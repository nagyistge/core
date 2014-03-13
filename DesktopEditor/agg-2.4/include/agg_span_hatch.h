#ifndef AGG_SPAN_HATCH_INCLUDED
#define AGG_SPAN_HATCH_INCLUDED

#include <stdlib.h>
#include <string>
#include "agg_math.h"
#include "agg_array.h"
#include "agg_trans_affine.h"

namespace agg
{
	#define HATCH_TX_SIZE			8
	#define HATCH_TX_COUNT			54

	// 8 * 8 * 54
	#define HATCH_RESOURCE_SIZE		3456

	static const BYTE c_resource_hatches[HATCH_RESOURCE_SIZE] = {
		/* cross */
		0,0,0,0,0,0,0,0,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,0,0,0,0,0,0,0,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,

		/* dashDnDiag */
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,0,1,1,1,
		1,0,1,1,1,0,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,0,1,1,1,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* dashHorz */
		0,0,0,0,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* dashUpDiag */
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,0,1,1,1,0,
		1,1,0,1,1,1,0,1,
		1,0,1,1,1,0,1,1,
		0,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* dashVert */
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,0,1,1,1,

		/* diagBrick */
		1,1,1,1,1,1,1,0,
		1,1,1,1,1,1,0,1,
		1,1,1,1,1,0,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,0,0,1,1,1,
		1,1,0,1,1,0,1,1,
		1,0,1,1,1,1,0,1,
		0,1,1,1,1,1,1,0,

		/* diagCross */
		0,1,1,1,1,1,0,1,
		1,0,1,1,1,0,1,1,
		1,1,0,1,0,1,1,1,
		1,1,1,0,1,1,1,1,
		1,1,0,1,0,1,1,1,
		1,0,1,1,1,0,1,1,
		0,1,1,1,1,1,0,1,
		1,1,1,1,1,1,1,0,

		/* divot */
		1,1,1,1,1,1,1,1,
		1,1,1,0,1,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,0,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,0,
		0,1,1,1,1,1,1,1,

		/* dkDnDiag */
		0,0,1,1,0,0,1,1,
		1,0,0,1,1,0,0,1,
		1,1,0,0,1,1,0,0,
		0,1,1,0,0,1,1,0,
		0,0,1,1,0,0,1,1,
		1,0,0,1,1,0,0,1,
		1,1,0,0,1,1,0,0,
		0,1,1,0,0,1,1,0,

		/* dkHorz */
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* dkUpDiag */
		1,1,0,0,1,1,0,0,
		1,0,0,1,1,0,0,1,
		0,0,1,1,0,0,1,1,
		0,1,1,0,0,1,1,0,
		1,1,0,0,1,1,0,0,
		1,0,0,1,1,0,0,1,
		0,0,1,1,0,0,1,1,
		0,1,1,0,0,1,1,0,

		/* dkVert */
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,
		0,0,1,1,0,0,1,1,

		/* dnDiag */
		0,1,1,1,0,1,1,1,
		1,0,1,1,1,0,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,0,1,1,1,0,
		0,1,1,1,0,1,1,1,
		1,0,1,1,1,0,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,0,1,1,1,0,

		/* dotDmnd */
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,1,1,1,1,1,

		/* dotGrid */
		0,1,0,1,0,1,0,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* horz */
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* horzBrick */
		0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		1,1,1,1,0,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,0,1,1,1,

		/* lgCheck */
		0,0,0,0,1,1,1,1,
		0,0,0,0,1,1,1,1,
		0,0,0,0,1,1,1,1,
		0,0,0,0,1,1,1,1,
		1,1,1,1,0,0,0,0,
		1,1,1,1,0,0,0,0,
		1,1,1,1,0,0,0,0,
		1,1,1,1,0,0,0,0,

		/* lgConfetti */
		0,1,0,0,1,1,1,0,
		1,1,0,0,1,1,1,1,
		1,1,1,1,1,1,0,0,
		1,1,1,0,0,1,0,0,
		0,0,1,0,0,1,1,1,
		0,0,1,1,1,1,1,1,
		1,1,1,1,0,0,1,1,
		0,1,1,1,0,0,1,0,

		/* lgGrid */
		0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,

		/* ltDnDiag */
		0,1,1,1,0,1,1,1,
		1,0,1,1,1,0,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,0,1,1,1,0,
		0,1,1,1,0,1,1,1,
		1,0,1,1,1,0,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,0,1,1,1,0,

		/* ltHorz */
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* ltUpDiag */
		1,1,1,0,1,1,1,0,
		1,1,0,1,1,1,0,1,
		1,0,1,1,1,0,1,1,
		0,1,1,1,0,1,1,1,
		1,1,1,0,1,1,1,0,
		1,1,0,1,1,1,0,1,
		1,0,1,1,1,0,1,1,
		0,1,1,1,0,1,1,1,

		/* ltVert */
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,

		/* narHorz */
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,

		/* narVert */
		1,0,1,0,1,0,1,0,
		1,0,1,0,1,0,1,0,
		1,0,1,0,1,0,1,0,
		1,0,1,0,1,0,1,0,
		1,0,1,0,1,0,1,0,
		1,0,1,0,1,0,1,0,
		1,0,1,0,1,0,1,0,
		1,0,1,0,1,0,1,0,

		/* openDmnd */
		0,1,1,1,1,1,0,1,
		1,0,1,1,1,0,1,1,
		1,1,0,1,0,1,1,1,
		1,1,1,0,1,1,1,1,
		1,1,0,1,0,1,1,1,
		1,0,1,1,1,0,1,1,
		0,1,1,1,1,1,0,1,
		1,1,1,1,1,1,1,0,

		/* pct10 */
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,

		/* pct20 */
		0,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,0,1,1,1,0,1,
		1,1,1,1,1,1,1,1,

		/* pct25 */
		0,1,1,1,0,1,1,1,
		1,1,0,1,1,1,0,1,
		0,1,1,1,0,1,1,1,
		1,1,0,1,1,1,0,1,
		0,1,1,1,0,1,1,1,
		1,1,0,1,1,1,0,1,
		0,1,1,1,0,1,1,1,
		1,1,0,1,1,1,0,1,

		/* pct30 */
		0,1,0,1,0,1,0,1,
		1,0,1,1,1,0,1,1,
		0,1,0,1,0,1,0,1,
		1,1,1,0,1,1,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,1,1,0,1,1,
		0,1,0,1,0,1,0,1,
		1,1,1,0,1,1,1,0,

		/* pct40 */
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,1,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,1,1,0,1,0,1,0,

		/* pct5 */
		0,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* pct50 */
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,

		/* pct60 */
		0,0,0,1,0,0,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,0,0,1,0,0,
		1,0,1,0,1,0,1,0,
		0,0,0,1,0,0,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,0,0,1,0,0,
		1,0,1,0,1,0,1,0,

		/* pct70 */
		1,0,0,0,1,0,0,0,
		0,0,1,0,0,0,1,0,
		1,0,0,0,1,0,0,0,
		0,0,1,0,0,0,1,0,
		1,0,0,0,1,0,0,0,
		0,0,1,0,0,0,1,0,
		1,0,0,0,1,0,0,0,
		0,0,1,0,0,0,1,0,

		/* pct75 */
		1,0,0,0,1,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,1,0,0,0,1,0,
		0,0,0,0,0,0,0,0,
		1,0,0,0,1,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,1,0,0,0,1,0,
		0,0,0,0,0,0,0,0,

		/* pct80 */
		0,0,0,1,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,

		/* pct90 */
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,1,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,

		/* plaid */
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,0,0,0,1,1,1,1,
		0,0,0,0,1,1,1,1,
		0,0,0,0,1,1,1,1,
		0,0,0,0,1,1,1,1,

		/* shingle */
		1,1,1,1,1,1,0,0,
		0,1,1,1,1,0,1,1,
		1,0,1,1,0,1,1,1,
		1,1,0,0,1,1,1,1,
		1,1,1,1,0,0,1,1,
		1,1,1,1,1,1,0,1,
		1,1,1,1,1,1,1,0,
		1,1,1,1,1,1,1,0,

		/* smCheck */
		0,1,1,0,0,1,1,0,
		1,0,0,1,1,0,0,1,
		1,0,0,1,1,0,0,1,
		0,1,1,0,0,1,1,0,
		0,1,1,0,0,1,1,0,
		1,0,0,1,1,0,0,1,
		1,0,0,1,1,0,0,1,
		0,1,1,0,0,1,1,0,

		/* smConfetti */
		0,1,1,1,1,1,1,1,
		1,1,1,1,0,1,1,1,
		1,0,1,1,1,1,1,1,
		1,1,1,1,1,1,0,1,
		1,1,1,0,1,1,1,1,
		1,1,1,1,1,1,1,0,
		1,1,0,1,1,1,1,1,
		1,1,1,1,1,0,1,1,

		/* smGrid */
		0,0,0,0,0,0,0,0,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,0,0,0,0,0,0,0,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,

		/* solidDmnd */
		1,1,1,0,1,1,1,1,
		1,1,0,0,0,1,1,1,
		1,0,0,0,0,0,1,1,
		0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,1,1,
		1,1,0,0,0,1,1,1,
		1,1,1,0,1,1,1,1,
		1,1,1,1,1,1,1,1,

		/* sphere */
		1,0,0,0,1,0,0,0,
		0,1,1,1,0,1,1,0,
		0,1,1,1,0,0,0,0,
		0,1,1,1,0,0,0,0,
		1,0,0,0,1,0,0,0,
		0,1,1,0,0,1,1,1,
		0,0,0,0,0,1,1,1,
		0,0,0,0,0,1,1,1,

		/* trellis */
		0,0,0,0,0,0,0,0,
		1,0,0,1,1,0,0,1,
		0,0,0,0,0,0,0,0,
		0,1,1,0,0,1,1,0,
		0,0,0,0,0,0,0,0,
		1,0,0,1,1,0,0,1,
		0,0,0,0,0,0,0,0,
		0,1,1,0,0,1,1,0,

		/* upDiag */
		1,1,0,0,1,1,0,0,
		1,0,0,1,1,0,0,1,
		0,0,1,1,0,0,1,1,
		0,1,1,0,0,1,1,0,
		1,1,0,0,1,1,0,0,
		1,0,0,1,1,0,0,1,
		0,0,1,1,0,0,1,1,
		0,1,1,0,0,1,1,0,

		/* vert */
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,
		0,1,1,1,0,1,1,1,

		/* wave */
		1,1,1,1,1,1,1,1,
		1,1,1,0,0,1,1,1,
		1,1,0,1,1,0,1,0,
		0,0,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		1,1,1,0,0,1,1,1,
		1,1,0,1,1,0,1,0,
		0,0,1,1,1,1,1,1,

		/* wdDnDiag */
		0,0,1,1,1,1,1,0,
		0,0,0,1,1,1,1,1,
		1,0,0,0,1,1,1,1,
		1,1,0,0,0,1,1,1,
		1,1,1,0,0,0,1,1,
		1,1,1,1,0,0,0,1,
		1,1,1,1,1,0,0,0,
		0,1,1,1,1,1,0,0,

		/* wdUpDiag */
		0,1,1,1,1,1,0,0,
		1,1,1,1,1,0,0,0,
		1,1,1,1,0,0,0,1,
		1,1,1,0,0,0,1,1,
		1,1,0,0,0,1,1,1,
		1,0,0,0,1,1,1,1,
		0,0,0,1,1,1,1,1,
		0,0,1,1,1,1,1,0,

		/* weave */
		0,1,1,1,0,1,1,1,
		1,0,1,0,1,0,1,1,
		1,1,0,1,1,1,0,1,
		1,0,1,1,1,0,1,1,
		0,1,1,1,0,1,1,1,
		1,1,1,0,1,0,1,1,
		1,1,0,1,1,1,0,1,
		1,0,1,0,1,1,1,0,

		/* zigZag */
		0,1,1,1,1,1,1,0,
		1,0,1,1,1,1,0,1,
		1,1,0,1,1,0,1,1,
		1,1,1,0,0,1,1,1,
		0,1,1,1,1,1,1,0,
		1,0,1,1,1,1,0,1,
		1,1,0,1,1,0,1,1,
		1,1,1,0,0,1,1,1
	};

	static const std::wstring c_resource_hatches_names[HATCH_TX_COUNT] = {
		L"cross",
		L"dashDnDiag",
		L"dashHorz",
		L"dashUpDiag",
		L"dashVert",
		L"diagBrick",
		L"diagCross",
		L"divot",
		L"dkDnDiag",
		L"dkHorz",
		L"dkUpDiag",
		L"dkVert",
		L"dnDiag",
		L"dotDmnd",
		L"dotGrid",
		L"horz",
		L"horzBrick",
		L"lgCheck",
		L"lgConfetti",
		L"lgGrid",
		L"ltDnDiag",
		L"ltHorz",
		L"ltUpDiag",
		L"ltVert",
		L"narHorz",
		L"narVert",
		L"openDmnd",
		L"pct10",
		L"pct20",
		L"pct25",
		L"pct30",
		L"pct40",
		L"pct5",
		L"pct50",
		L"pct60",
		L"pct70",
		L"pct75",
		L"pct80",
		L"pct90",
		L"plaid",
		L"shingle",
		L"smCheck",
		L"smConfetti",
		L"smGrid",
		L"solidDmnd",
		L"sphere",
		L"trellis",
		L"upDiag",
		L"vert",
		L"wave",
		L"wdDnDiag",
		L"wdUpDiag",
		L"weave",
		L"zigZag"
	};

	template<class ColorT>
    class agg_span_hatch
	{
	public:
		typedef ColorT color_type;

	private:
		enum
		{
			StateInit = 0,
			StateReady = 1,
		};

	private:
		int m_state;
		agg::trans_affine m_trans;

		int				m_offset;
		color_type		m_color1;
		color_type		m_color2;

	public:
		agg_span_hatch()
			: m_state( StateInit ), 
			m_offset( 0 ),
		{
		}

		void SetDirection(const std::wstring& name, const agg::trans_affine& trans)
		{
			m_trans = trans;
			
			for (int i = 0; i < HATCH_TX_COUNT; ++i)
			{
				if (c_resource_hatches_names[i] == name)
				{
					m_offset = i * HATCH_TX_SIZE * HATCH_TX_SIZE;
					break;
				}
			}
		}
		
        void prepare()
		{
			if( m_state != StateReady )
			{
				m_state = StateReady;
				memset( m_valid_table, 0, sizeof m_valid_table );
			}
		}

        void generate( color_type* span, int x, int y, unsigned len)
		{
			for( unsigned count = 0; count < len; ++count, ++x )
			{
				double _x = x;
				double _y = y;
				m_trans.transform(&_x, &_y);
				
				// TODO:
			}
		}
	};
}

#endif
