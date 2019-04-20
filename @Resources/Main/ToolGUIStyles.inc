; Tool GUI Styles
; - Styles used to fill the color box and bar

[Variables]
  BoxRectParam=0,0,[MeasureBoxSize],[MeasureBoxSize]
  BarRectParam=0,0,#BarWidth#,[MeasureBoxSize]

; ---------- STYLES ----------
; ---------- Hue ----------
[BoxStyleH]
  Shape=Rectangle #BoxRectParam# | Fill LinearGradient1 GradientWht
  Shape2=Rectangle #BoxRectParam# | Fill LinearGradient1 GradientSat
  Shape3=Rectangle #BoxRectParam# | Fill LinearGradient1 GradientVal
  GradientWht=225 | 255,255,255,255 ; 0.0 | 255,255,255,0 ; 1.0
  GradientSat=180 | [&LuaColorUtility:HueToRGB(#H#)],0 ; 0.0 | [&LuaColorUtility:HueToRGB(#H#)],255 ; 1.0
  GradientVal=270 | 0,0,0,0 ; 0.0 | 0,0,0,255 ; 1.0
  LeftMouseUpAction=[!SetVariable S "$MouseX:%$"][!SetVariable V "(100 - $MouseY:%$)"]#DoHSVtoRGB#

[BarStyleH]
  Shape=Rectangle #BarRectParam# | Fill LinearGradient GradientHue
  GradientHue=270 | 255,0,0 ; 0.0 | 255,0,255 ; 0.166 | 0,0,255 ; 0.333 | 0,255,255 ; 0.5 | 0,255,0 ; 0.666 | 255,255,0 ; 0.833 | 255,0,0 ; 1.0
  LeftMouseUpAction=[!SetVariable H "(Round((100 - $MouseY:%$) / 100 * 360))"]#DoHSVtoRGB#

; ---------- Saturation ----------
[BoxStyleS]
  Shape=Rectangle #BoxRectParam# | Fill LinearGradient GradientHue
  Shape2=Rectangle #BoxRectParam# | Fill Color 255,255,255,((100 - #S#) / 100 * 255)
  Shape3=Rectangle #BoxRectParam# | Fill LinearGradient GradientVal
  GradientHue=180 | 255,0,0 ; 0.0 | 255,255,0 ; 0.166 | 0,255,0 ; 0.333 | 0,255,255 ; 0.5 | 0,0,255 ; 0.666 | 255,0,255 ; 0.833 | 255,0,0 ; 1.0
  GradientVal=270 | 0,0,0,0 ; 0.0 | 0,0,0,255 ; 1.0
  LeftMouseUpAction=[!SetVariable H "(Round($MouseX:%$ / 100 * 360))"][!SetVariable V "(100 - $MouseY:%$)"]#DoHSVtoRGB#

[BarStyleS]
  Shape=Rectangle #BarRectParam# | Fill LinearGradient GradientWht
  Shape2=Rectangle #BarRectParam# | Fill LinearGradient GradientVal
  Shape3=Rectangle #BarRectParam# | Fill Color 0,0,0,((100 - #V#) / 100 * 255)
  GradientWht=270 | 255,255,255,0 ; 0.0 | 255,255,255,255 ; 1.0
  GradientVal=270 | [&LuaColorUtility:HueToRGB(#H#)],255 ; 0.0 | [&LuaColorUtility:HueToRGB(#H#)],0 ; 1.0
  LeftMouseUpAction=[!SetVariable S "(100 - $MouseY:%$)"]#DoHSVtoRGB#
  DynamicVariables=1

; ---------- Value ----------
[BoxStyleV]
  Shape=Rectangle #BoxRectParam# | Fill LinearGradient GradientHue
  Shape2=Rectangle #BoxRectParam# | Fill LinearGradient GradientSat
  Shape3=Rectangle #BoxRectParam# | Fill Color 0,0,0,((100 - #V#) / 100 * 255)
  GradientHue=180 | 255,0,0 ; 0.0 | 255,255,0 ; 0.166 | 0,255,0 ; 0.333 | 0,255,255 ; 0.5 | 0,0,255 ; 0.666 | 255,0,255 ; 0.833 | 255,0,0 ; 1.0
  GradientSat=270 | 255,255,255,0 ; 0.0 | 255,255,255,255 ; 1.0
  LeftMouseUpAction=[!SetVariable H "(Round($MouseX:%$ / 100 * 360))"][!SetVariable S "(100 - $MouseY:%$)"]#DoHSVtoRGB#

[BarStyleV]
  Shape=Rectangle #BarRectParam#
  Shape2=Rectangle #BarRectParam# | Fill LinearGradient GradientVal
  GradientVal=270 | [&LuaColorUtility:HueToRGB(#H#)] ; 0.0 | 0,0,0 ; 1.0
  LeftMouseUpAction=[!SetVariable V "(100 - $MouseY:%$)"]#DoHSVtoRGB#

; ---------- Red ----------
[BoxStyleR]
  Shape=Rectangle #BoxRectParam# | Fill LinearGradient GradientCyn
  Shape2=Rectangle #BoxRectParam# | Fill LinearGradient GradientGrn
  Shape3=Rectangle #BoxRectParam# | Fill LinearGradient GradientBlu
  Shape4=Rectangle #BoxRectParam# | Fill LinearGradient GradientRed
  GradientGrn=225 | #R#,255,0,255 ; 0.0 | #R#,255,0,0 ; 0.7
  GradientBlu=45 | #R#,0,255,255 ; 0.0 | #R#,0,255,0 ; 0.7
  GradientCyn=315 | #R#,255,255,255 ; 0.0 | #R#,255,255,0 ; 0.7
  GradientRed=135 | #R#,0,0,255 ; 0.0 | #R#,0,0,0 ; 0.7
  LeftMouseUpAction=[!SetVariable B "(Round($MouseX:%$ / 100 * 255))"][!SetVariable G "(Round((100 - $MouseY:%$) / 100 * 255))"]#DoRGBtoHSV#

[BarStyleR]
  Shape=Rectangle #BarRectParam#
  Shape2=Rectangle #BarRectParam# | Fill LinearGradient GradientVal
  GradientVal=270 | 255,#G#,#B# ; 0.0 | 0,#G#,#B# ; 1.0
  LeftMouseUpAction=[!SetVariable R "(Round((100 - $MouseY:%$) / 100 * 255))"]#DoRGBtoHSV#

; ---------- Green ----------
[BoxStyleG]
  Shape=Rectangle #BoxRectParam# | Fill LinearGradient GradientPrp
  Shape2=Rectangle #BoxRectParam# | Fill LinearGradient GradientRed
  Shape3=Rectangle #BoxRectParam# | Fill LinearGradient GradientBlu
  Shape4=Rectangle #BoxRectParam# | Fill LinearGradient GradientGrn
  GradientRed=225 | 255,#G#,0,255 ; 0.0 | 255,#G#,0,0 ; 0.7
  GradientBlu=45 | 0,#G#,255,255 ; 0.0 | 0,#G#,255,0 ; 0.7
  GradientPrp=315 | 255,#G#,255,255 ; 0.0 | 255,#G#,255,0 ; 0.7
  GradientGrn=135 | 0,#G#,0,255 ; 0.0 | 0,#G#,0,0 ; 0.7
  LeftMouseUpAction=[!SetVariable B "(Round($MouseX:%$ / 100 * 255))"][!SetVariable R "(Round((100 - $MouseY:%$) / 100 * 255))"]#DoRGBtoHSV#

[BarStyleG]
  Shape=Rectangle #BarRectParam#
  Shape2=Rectangle #BarRectParam# | Fill LinearGradient GradientGrn
  GradientGrn=270 | #R#,255,#B# ; 0.0 | #R#,0,#B# ; 1.0
  LeftMouseUpAction=[!SetVariable G "(Round((100 - $MouseY:%$) / 100 * 255))"]#DoRGBtoHSV#

; ---------- Blue -----------
[BoxStyleB]
  Shape=Rectangle #BoxRectParam# | Fill LinearGradient GradientYlw
  Shape2=Rectangle #BoxRectParam# | Fill LinearGradient GradientGrn
  Shape3=Rectangle #BoxRectParam# | Fill LinearGradient GradientRed
  Shape4=Rectangle #BoxRectParam# | Fill LinearGradient GradientBlu
  GradientGrn=225 | 0,255,#B#,255 ; 0.0 | 0,255,#B#,0 ; 0.7
  GradientRed=45 | 255,0,#B#,255 ; 0.0 | 255,0,#B#,0 ; 0.7
  GradientYlw=315 | 255,255,#B# ; 0.0 | 255,255,#B#,0 ; 0.7
  GradientBlu=135 | 0,0,#B#,255 ; 0.0 | 0,0,#B#,0 ; 0.7
  LeftMouseUpAction=[!SetVariable R "(Round($MouseX:%$ / 100 * 255))"][!SetVariable G "(Round((100 - $MouseY:%$) / 100 * 255))"]#DoRGBtoHSV#

[BarStyleB]
  Shape=Rectangle #BarRectParam#
  Shape2=Rectangle #BarRectParam# | Fill LinearGradient GradientBlu
  GradientBlu=270 | #R#,#G#,255 ; 0.0 | #R#,#G#,0 ; 1.0
  LeftMouseUpAction=[!SetVariable B "(Round((100 - $MouseY:%$) / 100 * 255))"]#DoRGBtoHSV#