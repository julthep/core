#pragma once

#include "BiffRecord.h"

namespace XLS
{;

class CFStreamCacheReader;


// Logical representation of Template record in BIFF8
class Template: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Template)
	BASE_OBJECT_DEFINE_CLASS_NAME(Template)
public:
	Template();
	~Template();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);
public:
	BO_ATTRIB_MARKUP_BEGIN
	BO_ATTRIB_MARKUP_END

};

} // namespace XLS
