[SwatchStartLayout1]
  Meter=Image
  X=([MeasureValueAnchorX] - #Padding#)
  Y=[MeasureSwatchStartY]
  DynamicVariables=1

[Swatch1]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(1)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(1)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(1)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch2]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(2)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(2)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(2)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch3]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(3)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(3)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(3)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch4]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(4)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(4)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(4)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch5]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(5)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(5)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(5)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[SwatchStartLayout2]
  Meter=Image
  X=([MeasureValueAnchorX] - #Padding#)
  Y=([MeasureSwatchStartY] + #ValueTitleHeight# + #Padding#)
  DynamicVariables=1

[Swatch6]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(6)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(6)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(6)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch7]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(7)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(7)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(7)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch8]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(8)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(8)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(8)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch9]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(9)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(9)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(9)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch10]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(10)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(10)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(10)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[SwatchStartLayout3]
  Meter=Image
  X=([MeasureValueAnchorX] - #Padding#)
  Y=([MeasureSwatchStartY] + 2 * (#ValueTitleHeight# + #Padding#))
  DynamicVariables=1

[Swatch11]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(11)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(11)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(11)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch12]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(12)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(12)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(12)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch13]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(13)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(13)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(13)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch14]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(14)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(14)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(14)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Swatch15]
  Meter=Shape
  MeterStyle=SwatchStyle
  Color=Fill Color [&LuaMainUtility:GetSwatchColor(15)]
  LeftMouseUpAction=[!CommandMeasure LuaMainUtility "SetSwatchToRGBVariable(15)"]#DoRGBtoHSV#
  RightMouseUpAction=#UpdateMainUtility#[!CommandMeasure LuaMainUtility "SetSwatchAsCurrentColor(15)"][!UpdateMeter #CURRENTSECTION#][!Redraw]