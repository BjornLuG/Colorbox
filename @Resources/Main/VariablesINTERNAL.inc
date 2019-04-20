; Internal Variables
; DO NOT change any of these variables unless you really know what you're doing
; Most variables defined here are tightly coalesced with Main.ini and MainUtility.lua

[Variables]
; ---------- LAYOUT -----------
  ; SkinSize is a variable from Variables.inc
  WindowWidth=(500 * #SkinSize#) 
  WindowHeight=(350 * #SkinSize#) 
  HeaderBarHeight=(30 * #SkinSize#) 
  CloseBtnWidth=(36 * #SkinSize#) 

  BarWidth=(30 * #SkinSize#) 

  ValueTitleWidth=(30 * #SkinSize#) 
  ValueTitleHeight=(20 * #SkinSize#) 
  ValueInputWidth=(40 * #SkinSize#) 
  ValueInputOffsetX=(4 * #SkinSize#) 
  HexInputWidth=(70 * #SkinSize#) 
  RGBInputWidth=(95 * #SkinSize#) 

  Padding=(7 * #SkinSize#) 

; ---------- POINTERS -----------
  BoxPointerX=0
  BoxPointerY=0
  BoxPointerRadius=(6 * #SkinSize#) 
  
  BarPointerY=0
  BarPointerWidth=(5 * #SkinSize#) 
  BarPointerHeight=(3 * #SkinSize#) 

; ---------- FONT SIZE ----------
  HeaderFontSize=(15 * #SkinSize#) 
  TextFontSize=(12 * #SkinSize#) 

; ---------- GROUPS ----------
  ValueGroup=Value
  ToolGUIGroup=ToolGUI

; ---------- SWATCHES ----------
  SwatchFileName=#@#Main\SavedSwatches.txt
  
; ---------- ACTIONS ----------
  UpdateValueGroup=[!UpdateMeterGroup #ValueGroup#]
  UpdateToolGUIGroup=[!UpdateMeasureGroup #ToolGUIGroup#][!UpdateMeterGroup #ToolGUIGroup#]
  UpdateMainUtility=[!UpdateMeasure "LuaMainUtility"]
  UpdateHSVtoRGB=[!CommandMeasure LuaMainUtility "UpdateHSVtoRGB()"]
  UpdateRGBtoHSV=[!CommandMeasure LuaMainUtility "UpdateRGBtoHSV()"]
  UpdateHextoAll=[!CommandMeasure LuaMainUtility "UpdateHextoAll()"]
  UpdateRGBtoHex=[!CommandMeasure LuaMainUtility "UpdateRGBtoHex()"]
  UpdatePointers=[!CommandMeasure LuaMainUtility "UpdatePointers()"]
  DoHSVtoRGB=#UpdateMainUtility##UpdateHSVtoRGB##UpdateRGBtoHex##UpdatePointers##UpdateValueGroup#[!Redraw]
  DoRGBtoHSV=#UpdateMainUtility##UpdateRGBtoHSV##UpdateRGBtoHex##UpdatePointers##UpdateValueGroup#[!Redraw]
  DoHextoAll=#UpdateMainUtility##UpdateHextoAll##UpdatePointers##UpdateValueGroup#[!Redraw]
  DoToolGUIChange=#UpdateMainUtility##UpdatePointers##UpdateToolGUIGroup#[!Redraw]