#pragma once

#include "BiffRecordContinued.h"

namespace XLS
{


// Logical representation of SXLI record in BIFF8
class SXLI: public BiffRecordContinued
{
	BIFF_RECORD_DEFINE_TYPE_INFO(SXLI)
	BASE_OBJECT_DEFINE_CLASS_NAME(SXLI)
public:
	SXLI();
	~SXLI();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);
	
	static const ElementType	type = typeSXLI;

};

} // namespace XLS

