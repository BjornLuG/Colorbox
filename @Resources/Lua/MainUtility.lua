-- MainUtility.lua

toolToIndex = 
{
    ['H'] = 1,
    ['S'] = 2,
    ['V'] = 3,
    ['R'] = 4,
    ['G'] = 5,
    ['B'] = 6
}

function Initialize()
    dofile(SKIN:GetVariable('@') .. '\\Lua\\ColorUtility.lua')
    dofile(SKIN:GetVariable('@') .. '\\Lua\\saveTableToFile.lua')

    -- Constants
    activeToolColor = SKIN:GetVariable('WindowColor3')
    inactiveToolColor = SKIN:GetVariable('WindowColor2')
    swatchFileName = SKIN:GetVariable('SwatchFileName')
    incVariables = SKIN:GetVariable('IncVariables')
    
    -- Dynamic
    currentTool = SKIN:GetVariable('CurrentTool')

    h,s,v,r,g,b = 0,0,0,0,0,0
    hex = ""

    swatchTable = table.load(swatchFileName)

    if swatchTable == nil then
        swatchTable = {}
        table.save(swatchTable, swatchFileName)
    end
end

-- ---------- HELPERS ----------
local function Clamp(num, min, max)
    if     num < min then return min
    elseif num > max then return max
    else                  return num
    end
end

function GetToolColor(tool)
    if currentTool == tool then
        return activeToolColor
    else
        return inactiveToolColor
    end
end

function GetCurrentToolIndex()
    return toolToIndex[currentTool]
end

function DoRGBInput(input)
    r,g,b = FormatRGB(input)

    SKIN:Bang('!SetVariable R ' .. r)
    SKIN:Bang('!SetVariable G ' .. g)
    SKIN:Bang('!SetVariable B ' .. b)
end

-- ---------- SWATCH ----------
function GetSwatchColor(index)
    return swatchTable[tostring(index)] or "0,0,0"
end

function SetSwatchAsCurrentColor(index)
    swatchTable[tostring(index)] = r .. "," .. g .. "," .. b
    table.save(swatchTable, swatchFileName)
end

function SetSwatchToRGBVariable(index)
    local rgb = GetSwatchColor(tostring(index))
    local comma1 = string.find(rgb, ",", 1)
    local comma2 = string.find(rgb, ",", comma1 + 1)

    SKIN:Bang('!SetVariable R ' .. string.sub(rgb, 1, comma1 - 1))
    SKIN:Bang('!SetVariable G ' .. string.sub(rgb, comma1 + 1, comma2 - 1))
    SKIN:Bang('!SetVariable B ' .. string.sub(rgb, comma2 + 1, string.len(rgb)))
end

-- ---------- UPDATES ----------
local function UpdateVariables()
    currentTool = SKIN:GetVariable('CurrentTool') 

    h = tonumber(SKIN:GetVariable('H'))
    s = tonumber(SKIN:GetVariable('S'))
    v = tonumber(SKIN:GetVariable('V'))

    r = tonumber(SKIN:GetVariable('R'))
    g = tonumber(SKIN:GetVariable('G'))
    b = tonumber(SKIN:GetVariable('B'))

    hex = SKIN:GetVariable('Hex')

    if toolToIndex[currentTool] == nil then currentTool = 'H' end
    if h >= 360 then h = 0 end
end

local function WriteVariables()
    SKIN:Bang('!WriteKeyValue Variables CurrentTool ' .. currentTool .. ' ' .. incVariables)

    SKIN:Bang('!WriteKeyValue Variables H ' .. h .. ' ' .. incVariables)
    SKIN:Bang('!WriteKeyValue Variables S ' .. s .. ' ' .. incVariables)
    SKIN:Bang('!WriteKeyValue Variables V ' .. v .. ' ' .. incVariables)
    SKIN:Bang('!WriteKeyValue Variables R ' .. r .. ' ' .. incVariables)
    SKIN:Bang('!WriteKeyValue Variables G ' .. g .. ' ' .. incVariables)
    SKIN:Bang('!WriteKeyValue Variables B ' .. b .. ' ' .. incVariables)

    SKIN:Bang('!WriteKeyValue Variables Hex ' .. hex .. ' ' .. incVariables)
end

function Update()
    UpdateVariables()
    WriteVariables()
end

function UpdateHSVtoRGB()
    r,g,b = HSVtoRGB(h,s,v)

    SKIN:Bang('!SetVariable R ' .. r)
    SKIN:Bang('!SetVariable G ' .. g)
    SKIN:Bang('!SetVariable B ' .. b)
end

function UpdateRGBtoHSV()
    h,s,v = RGBtoHSV(r,g,b)

    SKIN:Bang('!SetVariable H ' .. h)
    SKIN:Bang('!SetVariable S ' .. s)
    SKIN:Bang('!SetVariable V ' .. v)
end

function UpdateRGBtoHex()
    SKIN:Bang('!SetVariable Hex ' .. RGBtoHex(r,g,b))
end

function UpdateHextoAll()
    r,g,b = HextoRGB(hex)
    h,s,v = RGBtoHSV(r,g,b)

    SKIN:Bang('!SetVariable H ' .. h)
    SKIN:Bang('!SetVariable S ' .. s)
    SKIN:Bang('!SetVariable V ' .. v)
    SKIN:Bang('!SetVariable R ' .. r)
    SKIN:Bang('!SetVariable G ' .. g)
    SKIN:Bang('!SetVariable B ' .. b)
end

function UpdatePointers()
    local barY = 0
    local boxX = 0
    local boxY = 0

    if currentTool == "H" then
        barY = (360 - Clamp(h, 0, 360)) / 360
        boxX =        Clamp(s, 0, 100)  / 100
        boxY = (100 - Clamp(v, 0, 100)) / 100

        if barY >= 1 then barY = 0 end
        
    elseif currentTool == "S" then
        barY = (100 - Clamp(s, 0, 100)) / 100
        boxX =        Clamp(h, 0, 360)  / 360
        boxY = (100 - Clamp(v, 0, 100)) / 100

    elseif currentTool == "V" then
        barY = (100 - Clamp(v, 0, 100)) / 100
        boxX =        Clamp(h, 0, 360)  / 360
        boxY = (100 - Clamp(s, 0, 100)) / 100

    elseif currentTool == "R" then
        barY = (255 - Clamp(r, 0, 255)) / 255
        boxX =        Clamp(b, 0, 255)  / 255
        boxY = (255 - Clamp(g, 0, 255)) / 255

    elseif currentTool == "G" then
        barY = (255 - Clamp(g, 0, 255)) / 255
        boxX =        Clamp(b, 0, 255)  / 255
        boxY = (255 - Clamp(r, 0, 255)) / 255

    elseif currentTool == "B" then
        barY = (255 - Clamp(b, 0, 255)) / 255
        boxX =        Clamp(r, 0, 255)  / 255
        boxY = (255 - Clamp(g, 0, 255)) / 255

    else
        SKIN:Bang('!Log "currentTool index out of range"')
    end
    
    SKIN:Bang('!SetVariable BarPointerY ' .. barY)
    SKIN:Bang('!SetVariable BoxPointerX ' .. boxX)
    SKIN:Bang('!SetVariable BoxPointerY ' .. boxY)
end