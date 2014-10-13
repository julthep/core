#pragma once

#include "BiffStructure.h"
#include <Logic/Biff_structures/CellRangeRef.h>

namespace XLS
{;

class CFRecord;

class SqRefU : public BiffStructure
{
	BASE_OBJECT_DEFINE_CLASS_NAME(SqRefU)
public:
	BiffStructurePtr clone();

	//virtual void setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	//virtual void getXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

	const CellRef getLocationFirstCell() const;

private:
	std::wstring  sqref;
};

} // namespace XLS
