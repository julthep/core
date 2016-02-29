#include "LabelSst.h"

namespace XLS
{

LabelSst::LabelSst()
{
}


LabelSst::~LabelSst()
{
}


BaseObjectPtr LabelSst::clone()
{
	return BaseObjectPtr(new LabelSst(*this));
}


void LabelSst::writeFields(CFRecord& record)
{
	resender.store(record);
	record << cell << isst;
}


void LabelSst::readFields(CFRecord& record)
{
	global_info_ = record.getGlobalWorkbookInfo();

	record >> cell >> isst;
}

const CellRef LabelSst::getLocation() const
{
	return cell.getLocation();
}

int LabelSst::serialize(std::wostream & stream)
{
	CP_XML_WRITER(stream)    
    {
		int row = cell.rw;
			
		std::wstring ref = cell.getLocation().toString();// getColRowRef(i, row);
		CP_XML_NODE(L"c")
		{
			CP_XML_ATTR(L"r", ref);

			int st = (int)cell.ixfe - global_info_->cellStyleXfs_count;
			if (cell.ixfe > global_info_->cellStyleXfs_count)
			{
				CP_XML_ATTR(L"s", cell.ixfe - global_info_->cellStyleXfs_count);
			}
			
			CP_XML_ATTR(L"t", L"s");
			
			if (isst.value())
			{
				CP_XML_NODE(L"v")
				{
					CP_XML_STREAM() << isst;
				}
			}
		}			
	}
	return 0;
}
} // namespace XLS

