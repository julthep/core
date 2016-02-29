#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of SXEx record in BIFF8
class SXEx: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(SXEx)
	BASE_OBJECT_DEFINE_CLASS_NAME(SXEx)
public:
	SXEx();
	~SXEx();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeSXEx;


};

} // namespace XLS

