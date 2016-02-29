#pragma once

#include "BiffRecord.h"

namespace XLS
{


// Logical representation of CatLab record in BIFF8
class CatLab: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(CatLab)
	BASE_OBJECT_DEFINE_CLASS_NAME(CatLab)
public:
	CatLab();
	~CatLab();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeCatLab;

//-----------------------------
	_UINT16 wOffset;
	_UINT16 at;
	bool cAutoCatLabelReal;
};

} // namespace XLS

