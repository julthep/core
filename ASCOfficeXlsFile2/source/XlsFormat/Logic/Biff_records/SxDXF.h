#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of SxDXF record in BIFF8
class SxDXF: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(SxDXF)
	BASE_OBJECT_DEFINE_CLASS_NAME(SxDXF)
public:
	SxDXF();
	~SxDXF();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeSxDXF;
};

} // namespace XLS

