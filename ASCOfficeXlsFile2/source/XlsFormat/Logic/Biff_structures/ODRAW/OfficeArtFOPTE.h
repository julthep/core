#pragma once

#include "../BiffStructure.h"
#include "OfficeArtCOLORREF.h"
#include "OfficeArtBlip.h"
#include "../FixedPoint.h"
#include "IMsoArray.h"
#include "MSOSHADECOLOR.h"
#include "MSO_enums.h"
#include <Logic/Biff_structures/HyperlinkObject.h>

#include "../../../ASCOfficePPTXFile/Editor/Drawing/Shapes/BaseShape/PPTShape/Enums.h"

namespace XLS
{
	class CFRecord;
}

namespace ODRAW
{
		enum MSOPATHTYPE
		{
			msopathLineTo,
			msopathCurveTo,
			msopathMoveTo,
			msopathClose,
			msopathEnd,
			msopathEscape,
			msopathClientEscape,
			msopathInvalid
		};

		enum MSOPATHESCAPE
		{
			msopathEscapeExtension 				=	0x00000000,	
			msopathEscapeAngleEllipseTo  		=	0x00000001,
			msopathEscapeAngleEllipse 	 		=	0x00000002,
			msopathEscapeArcTo  				=	0x00000003,
			msopathEscapeArc  					=	0x00000004,
			msopathEscapeClockwiseArcTo  		=	0x00000005,
			msopathEscapeClockwiseArc 	 		=	0x00000006,
			msopathEscapeEllipticalQuadrantX  	=	0x00000007,
			msopathEscapeEllipticalQuadrantY 	=	0x00000008,
			msopathEscapeQuadraticBezier 	 	=	0x00000009,
			msopathEscapeNoFill  				=	0x0000000A,
			msopathEscapeNoLine  				=	0x0000000B,
			msopathEscapeAutoLine  				=	0x0000000C,
			msopathEscapeAutoCurve  			=	0x0000000D,
			msopathEscapeCornerLine  			=	0x0000000E,
			msopathEscapeCornerCurve 			=	0x0000000F,
			msopathEscapeSmoothLine  			=	0x00000010,
			msopathEscapeSmoothCurve  			=	0x00000011,
			msopathEscapeSymmetricLine 			=	0x00000012,
			msopathEscapeSymmetricCurve 		=	0x00000013,
			msopathEscapeFreeform 				=	0x00000014,
			msopathEscapeFillColor 				=	0x00000015,
			msopathEscapeLineColor 				=	0x00000016
		};
class OfficeArtFOPTE;
typedef boost::shared_ptr<OfficeArtFOPTE> OfficeArtFOPTEPtr;

class OfficeArtFOPTE : public XLS::BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(OfficeArtFOPTE)
public:
	XLS::BiffStructurePtr clone();

	static const XLS::ElementType	type = XLS::typeOfficeArtFOPTE;
	
	virtual void store(XLS::CFRecord& record);

protected:
	virtual void load(XLS::CFRecord& record);

public:
	static OfficeArtFOPTEPtr load_and_create(XLS::CFRecord& record);
	virtual void ReadComplexData(XLS::CFRecord& record);


public:
	unsigned short opid;
	bool fBid;
	bool fComplex;
    _INT32 op;
};


class fillColor : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillColor)
};

class FixedPoint : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillColor)
	virtual void load(XLS::CFRecord& record);
	
	double dVal;
};
class TextBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(TextBooleanProperties)
	
	virtual void load(XLS::CFRecord& record);
	
	bool fFitShapeToText;
	bool fAutoTextMargin;
	bool fSelectText;

	bool fUsefFitShapeToText;
	bool fUsefAutoTextMargin;
	bool fUsefSelectText;
};

class GeometryTextBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(TextBooleanProperties)
	
	virtual void load(XLS::CFRecord& record);
	
	bool gFReverseRows;
	bool fGtext;
	bool fVertical;
	bool fKern;
	bool fStretch;
	bool fTight;
	bool fBestFit;
	bool fShrinkFit;
	bool fNormalize;
	bool fDxMeasure;
	bool fBold;
	bool fItalic;
	bool fUnderline;
	bool fShadow;
	bool fSmallcaps;
	bool fStrikethrough;

	bool fUsegFReverseRows;
	bool fUsefGtext	;
	bool fUsegFVertical	;
	bool fUsegtextFKern	;
	bool fUsegTight	;
	bool fUsegFStretch	;
	bool fUsegFShrinkFit;
	bool fUsegFBestFit	;
	bool fUsegFNormalize;
	bool fUsegFDxMeasure;
	bool fUsegFBold		;
	bool fUsegFItalic	;
	bool fUsegFUnderline	;
	bool fUsegFShadow	;
	bool fUsegFSmallcaps	;
	bool fUsegFStrikethrough;
};

class lineColor : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineColor)
};

class fillType : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillType)
};

class pib : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(pib)
};

class pictureId : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(pictureId)
};

class pictureRecolor : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(pictureRecolor)
};


class fillOpacity : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillOpacity)
};

class fillBackColor : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillBackColor)
};

class fillBackOpacity : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillBackOpacity)
};

class fillCrMod : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillCrMod)
};

class fillWidth : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillWidth)
};

class fillShadeType : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillShadeType)
};

class FillStyleBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(FillStyleBooleanProperties)
	
	virtual void load(XLS::CFRecord& record);

	bool fNoFillHitTest;
	bool fillUseRect;
	bool fillShape;
	bool fHitTestFill;
	bool fFilled ;
	bool fUseShapeAnchor;
	bool fRecolorFillAsPicture;
	bool fUsefNoFillHitTest;
	bool fUsefillUseRect;
	bool fUsefillShape;
	bool fUsefHitTestFill;
	bool fUsefFilled;
	bool fUsefUseShapeAnchor;
	bool fUsefRecolorFillAsPicture;
};

class fillBlip : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillBlip)

	virtual void ReadComplexData(XLS::CFRecord& record);

	OfficeArtBlipPtr blip;
};
class BlipBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(BlipBooleanProperties)
};
class ShapeBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(ShapeBooleanProperties)
};

class GroupShapeBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(GroupShapeBooleanProperties)
};
class anyString : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(anyString)

	virtual void ReadComplexData(XLS::CFRecord& record);

	std::wstring string_;
};


class fillBlipFlags : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillBlipFlags)
	//enum MSOBLIPFLAGS
	//{
	//	msoblipflagComment		= 0x00000000,
	//	msoblipflagFile			= 0x00000001,
	//	msoblipflagURL			= 0x00000002,
	//	msoblipflagDoNotSave	= 0x00000004,
	//	msoblipflagLinkToFile	= 0x00000008,
	//};
};

class fillHeight : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillHeight)
};

class fillAngle : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillAngle)

};

class fillFocus : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillFocus)
};

class fillToLeft : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillToLeft)
};

class fillToTop : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillToTop)
};

class fillToRight : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillToRight)
};

class fillToBottom : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillToBottom)
};

class fillRectLeft : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillRectLeft)
};

class fillRectTop : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillRectTop)
};

class fillRectRight : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillRectRight)
};

class fillRectBottom : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillRectBottom)
};

class fillDztype : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillDztype)
};

class fillShadePreset : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillShadePreset)
};

class fillShadeColors : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillShadeColors)

	virtual void ReadComplexData(XLS::CFRecord& record);

	IMsoArray<MSOSHADECOLOR> fillShadeColors_complex;
};


class fillShapeOriginX : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillShapeOriginX)
};

class fillShapeOriginY : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillShapeOriginY)
};

class fillOriginX : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillOriginX)
};

class fillOriginY : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillOriginY)
};

class fillColorExt : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillColorExt)
};

class reserved415 : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(reserved415)
};

class reserved417 : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(reserved417)
};

class reserved419 : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(reserved419)
};

class reserved421 : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(reserved421)
};

class reserved422 : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(reserved422)
};

class reserved423 : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(reserved423)
};

class fillBackColorExt : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillBackColorExt)
};

class fillColorExtMod : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillColorExtMod)
};

class fillBackColorExtMod : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(fillBackColorExtMod)
};

class ProtectionBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(ProtectionBooleanProperties)

	virtual void load(XLS::CFRecord& record);

	bool fLockAgainstGrouping ;
	bool fLockAdjustHandles ;
	bool fLockText ;
	bool fLockVertices ;
	bool fLockCropping ;
	bool fLockAgainstSelect ;
	bool fLockPosition ;
	bool fLockAspectRatio ;
	bool fLockRotation ;
	bool fLockAgainstUngrouping ;
	bool fUsefLockAgainstGrouping ;
	bool fUsefLockAdjustHandles ;
	bool fUsefLockText ;
	bool fUsefLockVertices ;
	bool fUsefLockCropping ;
	bool fUsefLockAgainstSelect;
	bool fUsefLockPosition ;
	bool fUsefLockAspectRatio;
	bool fUsefLockRotation ;
	bool fUsefLockAgainstUngrouping;
};

class LineStyleBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(LineStyleBooleanProperties)

	virtual void load(XLS::CFRecord& record);

	bool fNoLineDrawDash;
	bool fLineFillShape;
	bool fHitTestLine ;
	bool fLine ;
	bool fArrowheadsOK;
	bool fInsetPenOK ;
	bool fInsetPen ;
	bool fLineOpaqueBackColor;
	bool fUsefNoLineDrawDash;
	bool fUsefLineFillShape ;
	bool fUsefHitTestLine ;
	bool fUsefLine;
	bool fUsefArrowheadsOK ;
	bool fUsefInsetPenOK;
	bool fUsefInsetPen;
	bool fUsefLineOpaqueBackColor ;
};

class ShadowStyleBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(ShadowStyleBooleanProperties)
	
	virtual void load(XLS::CFRecord& record);

	bool fshadowObscured ;
	bool fShadow ;
	bool fUsefshadowObscured ;
	bool fUsefShadow ;
};

class GeometryBooleanProperties : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(GeometryBooleanProperties)
	
	virtual void load(XLS::CFRecord& record);

	bool fUsefShadowOK;
	bool fUsef3DOK ;
	bool fUsefLineOK ;
	bool fUsefGtextOK ;
	bool fUsefFillShadeShapeOK ;
	bool fUsefFillOK ;

	bool fShadowOK;
	bool f3DOK;
	bool fLineOK;
	bool fGtextOK;
	bool fFillShadeShapeOK;
	bool fFillOK;
};

class lineWidth : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineWidth)
};

class lineMiterLimit : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineMiterLimit)
};

class lineDashing : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineDashing)
};

class lineStyle : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineStyle)
};

class cropFromBottom : public FixedPoint 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(cropFromBottom)
};

class cropFromTop : public FixedPoint 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(cropFromTop)
};

class cropFromLeft : public FixedPoint 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(cropFromLeft)
};
class cropFromRight : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(cropFromRight)
};

class Rotation : public FixedPoint 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(Rotation)
};
class OfficeArtShapeRectCoord : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(OfficeArtShapeRectCoord)
};

class shadowOpacity : public FixedPoint
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(shadowOpacity)
};

class MSOPOINT : public XLS::BiffStructure  
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(MSOPOINT)
	
	MSOPOINT(unsigned short cbElement_);
	MSOPOINT();

	XLS::BiffStructurePtr clone();

	virtual void load(XLS::CFRecord& record);
	virtual void store(XLS::CFRecord& record){}

	static const XLS::ElementType	type = XLS::typeOfficeArtRecord;

    int x;
    int y;

	int cbElement;
};

class MSOPATHINFO : public XLS::BiffStructure 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(MSOPATHINFO)

	MSOPATHINFO();
	MSOPATHINFO(unsigned short cbElement_);

	XLS::BiffStructurePtr clone();

	virtual void load(XLS::CFRecord& record);
	virtual void store(XLS::CFRecord& record){}

	static const XLS::ElementType	type = XLS::typeOfficeArtRecord;

	//enum msoPathSegmentType
	//{
	//	msopathLineTo = 0,
	//	msopathCurveTo,
	//	msopathMoveTo,
	//	msopathClose,
	//	msopathEnd,
	//	msopathEscape,
	//	msopathClientEscape
	//};
	unsigned short		cbElement;

	MSOPATHTYPE			typeSegment;
	short				Segments;
	short				VertexCount;
	MSOPATHESCAPE		EscapeCode;
};

class ShapePath : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(ShapePath)

	enum msoShapePathType
	{
		msoshapeLines  =0, 
		msoshapeLinesClosed,
		msoshapeCurves,
		msoshapeCurvesClosed,
		msoshapeComplex
	};
};

class PVertices : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(PVertices)

	virtual void ReadComplexData(XLS::CFRecord& record);

	IMsoArray<MSOPOINT> path_complex;
};

class PSegmentInfo : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(PSegmentInfo)

	virtual void ReadComplexData(XLS::CFRecord& record);

	IMsoArray<MSOPATHINFO> path_complex;
};

class AdjustValue : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(AdjustValue)
};

class pAdjustHandles : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(pAdjustHandles)
};

class lineOpacity : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineOpacity)
};

class lineBackColor : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineBackColor)
};

class lineCrMod : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineCrMod)
};
class lineType : public OfficeArtFOPTE 
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(lineType)
};

class IHlink;
typedef boost::shared_ptr<IHlink> IHlinkPtr;

class IHlink : public XLS::BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(IHlink)

	IHlink(){}

	XLS::BiffStructurePtr clone();

	void load(XLS::CFRecord& record);
	void store(XLS::CFRecord& record){}
	
	static const XLS::ElementType	type = XLS::typeIHLink;

	_GUID_							CLSID_StdHlink;
	OSHARED::HyperlinkObject		hyperlink;
};

class pihlShape : public OfficeArtFOPTE
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(pihlShape)

	void ReadComplexData(XLS::CFRecord& record);

	IHlink IHlink_complex;
};



}
