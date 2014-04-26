#pragma once

#include <string>
#include <vector>
//
//#include "ods_drawing_context.h"
//#include "ods_comments_context.h"
//#include "ods_hyperlinks.h"

#include "office_elements.h"
#include "office_elements_create.h"


namespace cpdoccore {
namespace odf
{

class odf_conversion_context;
class odf_style_context;
class paragraph;

struct odf_text_state
{
	office_element_ptr	elm;
	std::wstring		style_name;

	office_element_ptr	style_elm;

	int level;
};

class odf_text_context: boost::noncopyable
{
public:
	odf_text_context(odf_style_context * styles_context_,odf_conversion_context *odf_context);
    ~odf_text_context();
public:
	void set_styles_context(odf_style_context*  styles_context);//��� embedded 
    
	void add_text_content(const std::wstring & text);
    
	void start_paragraph();
	void start_paragraph(office_element_ptr & elm);
    void end_paragraph();

	void start_element(office_element_ptr & elm); // t, h, list???
    void end_element();
 	
	void start_span(); 
    void end_span();
		
	std::vector<office_element_ptr> current_level_;//��������� ���������� ������ ������� ������������

	std::vector<odf_text_state> text_elements_list_;//���������, ������ , ... - �������� �������� (��� ����� �������� ���?? + ������� ��������????
private:
	paragraph * last_paragraph_;

	odf_style_context * styles_context_;
	odf_conversion_context *odf_context_;
};

}
}