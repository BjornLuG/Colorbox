; ---------- VALUES ----------
; ---------- STYLES ----------
[ValueTitleStyle]
Group=#ToolGUIGroup#
X=r
Y=R
W=#ValueTitleWidth#
H=#ValueTitleHeight#
FontFace=#Font#
FontSize=#TextFontSize#
FontColor=#TextColor#
StringAlign=Center
DynamicVariables=1

[ValueInputStyle]
Group=#ValueGroup#
X=r
Y=R
W=#ValueInputWidth#
H=#ValueTitleHeight#
FontFace=#Font#
FontSize=#TextFontSize#
FontColor=#TextColor#
DynamicVariables=1

; ---------- TITLE ----------
[ValueTitleLayoutStart]
Meter=Image
X=([MeasureValueAnchorX] + #ValueTitleWidth# / 2)
Y=#Padding#R
DynamicVariables=1

[MeterTitleH]
Meter=String
MeterStyle=ValueTitleStyle
Text="H"
ToolTipText="Hue"
SolidColor=[&LuaMainUtility:GetToolColor("H")]
LeftMouseUpAction=[!SetVariable CurrentTool "H"]#DoToolGUIChange#

[MeterTitleS]
Meter=String
MeterStyle=ValueTitleStyle
Text="S"
ToolTipText="Saturation"
SolidColor=[&LuaMainUtility:GetToolColor("S")]
LeftMouseUpAction=[!SetVariable CurrentTool "S"]#DoToolGUIChange#

[MeterTitleV]
Meter=String
MeterStyle=ValueTitleStyle
Text="V"
ToolTipText="Value"
SolidColor=[&LuaMainUtility:GetToolColor("V")]
LeftMouseUpAction=[!SetVariable CurrentTool "V"]#DoToolGUIChange#

[MeterTitleR]
Meter=String
MeterStyle=ValueTitleStyle
Text="R"
ToolTipText="Red"
SolidColor=[&LuaMainUtility:GetToolColor("R")]
LeftMouseUpAction=[!SetVariable CurrentTool "R"]#DoToolGUIChange#

[MeterTitleG]
Meter=String
MeterStyle=ValueTitleStyle
Text="G"
ToolTipText="Green"
SolidColor=[&LuaMainUtility:GetToolColor("G")]
LeftMouseUpAction=[!SetVariable CurrentTool "G"]#DoToolGUIChange#

[MeterTitleB]
Meter=String
MeterStyle=ValueTitleStyle
Text="B"
ToolTipText="Blue"
SolidColor=[&LuaMainUtility:GetToolColor("B")]
LeftMouseUpAction=[!SetVariable CurrentTool "B"]#DoToolGUIChange#

[MeterTitleHex]
Meter=String
MeterStyle=ValueTitleStyle
Group=#ValueGroup#
Y=#Padding#R
Text="#"
ToolTipText="Color Hex (Click to copy)"
LeftMouseUpAction=[!SetClip #Hex#]

[MeterTitleRGB]
Meter=String
MeterStyle=ValueTitleStyle
Group=#ValueGroup#
Text="RGB"
ToolTipText="Red,Green,Blue (Click to copy)"
LeftMouseUpAction=[!SetClip #R#,#G#,#B#]

; ---------- VALUE ----------
[ValueLayoutStart]
Meter=Image
X=R
Y=[MeterTitleH:Y]
DynamicVariables=1

[MeterValueH]
Meter=String
MeterStyle=ValueInputStyle
Text=#H#
LeftMouseUpAction=[!CommandMeasure MeasureInputH "ExecuteBatch 1"]

[MeterValueS]
Meter=String
MeterStyle=ValueInputStyle
Text=#S#
LeftMouseUpAction=[!CommandMeasure MeasureInputS "ExecuteBatch 1"]

[MeterValueV]
Meter=String
MeterStyle=ValueInputStyle
Text=#V#
LeftMouseUpAction=[!CommandMeasure MeasureInputV "ExecuteBatch 1"]

[MeterValueR]
Meter=String
MeterStyle=ValueInputStyle
Text=#R#
LeftMouseUpAction=[!CommandMeasure MeasureInputR "ExecuteBatch 1"]

[MeterValueG]
Meter=String
MeterStyle=ValueInputStyle
Text=#G#
LeftMouseUpAction=[!CommandMeasure MeasureInputG "ExecuteBatch 1"]

[MeterValueB]
Meter=String
MeterStyle=ValueInputStyle
Text=#B#
LeftMouseUpAction=[!CommandMeasure MeasureInputB "ExecuteBatch 1"]

[MeterValueHex]
Meter=String
MeterStyle=ValueInputStyle
Y=#Padding#R
Text=#Hex#
LeftMouseUpAction=[!CommandMeasure MeasureInputHex "ExecuteBatch 1"]

[MeterValueRGB]
Meter=String
MeterStyle=ValueInputStyle
Text=#R#,#G#,#B#
LeftMouseUpAction=[!CommandMeasure MeasureInputRGB "ExecuteBatch 1"]

; ---------- INPUT ----------
[MeasureInputH]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#ValueInputWidth#
  H=[MeterValueH:H]
  X=([MeterValueH:X] - #ValueInputOffsetX#)
  Y=[MeterValueH:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  InputNumber=1
  DefaultValue=#H#
  Command1=[!SetVariable H "(Clamp($UserInput$,0,360))"]#DoHSVtoRGB#
  DynamicVariables=1

[MeasureInputS]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#ValueInputWidth#
  H=[MeterValueS:H]
  X=([MeterValueS:X] - #ValueInputOffsetX#)
  Y=[MeterValueS:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  InputNumber=1
  DefaultValue=#S#
  Command1=[!SetVariable S "(Clamp($UserInput$,0,100))"]#DoHSVtoRGB#
  DynamicVariables=1

[MeasureInputV]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#ValueInputWidth#
  H=[MeterValueV:H]
  X=([MeterValueV:X] - #ValueInputOffsetX#)
  Y=[MeterValueV:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  InputNumber=1
  DefaultValue=#V#
  Command1=[!SetVariable V "(Clamp($UserInput$,0,100))"]#DoHSVtoRGB#
  DynamicVariables=1

[MeasureInputR]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#ValueInputWidth#
  H=[MeterValueR:H]
  X=([MeterValueR:X] - #ValueInputOffsetX#)
  Y=[MeterValueR:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  InputNumber=1
  DefaultValue=#R#
  Command1=[!SetVariable R "(Clamp($UserInput$,0,255))"]#DoRGBtoHSV#
  DynamicVariables=1

[MeasureInputG]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#ValueInputWidth#
  H=[MeterValueG:H]
  X=([MeterValueG:X] - #ValueInputOffsetX#)
  Y=[MeterValueG:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  InputNumber=1
  DefaultValue=#G#
  Command1=[!SetVariable G "(Clamp($UserInput$,0,255))"]#DoRGBtoHSV#
  DynamicVariables=1

[MeasureInputB]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#ValueInputWidth#
  H=[MeterValueB:H]
  X=([MeterValueB:X] - #ValueInputOffsetX#)
  Y=[MeterValueB:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  InputNumber=1
  DefaultValue=#B#
  Command1=[!SetVariable B "(Clamp($UserInput$,0,255))"]#DoRGBtoHSV#
  DynamicVariables=1

[MeasureInputHex]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#HexInputWidth#
  H=[MeterValueHex:H]
  X=([MeterValueHex:X] - #ValueInputOffsetX#)
  Y=[MeterValueHex:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  DefaultValue=#Hex#
  InputLimit=6
  Command1=[!SetVariable Hex """[&LuaColorUtility:FormatHex("$UserInput$")]"""]#DoHextoAll#
  DynamicVariables=1

[MeasureInputRGB]
  Measure=Plugin
  Plugin=InputText
  Group=#ValueGroup#
  W=#RGBInputWidth#
  H=[MeterValueRGB:H]
  X=([MeterValueRGB:X] - #ValueInputOffsetX#)
  Y=[MeterValueRGB:Y]
  FontFace=#Font#
  FontSize=#TextFontSize#
  FontColor=#TextColor#
  SolidColor=#WindowColor2#
  DefaultValue=#R#,#G#,#B#
  InputLimit=11
  Command1=[!CommandMeasure LuaMainUtility """DoRGBInput("$UserInput$")"""]#DoRGBtoHSV#
  DynamicVariables=1