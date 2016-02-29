#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of ScenMan record in BIFF8
class ScenMan: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(ScenMan)
	BASE_OBJECT_DEFINE_CLASS_NAME(ScenMan)
public:
	ScenMan();
	~ScenMan();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeScenMan;
};

} // namespace XLS

