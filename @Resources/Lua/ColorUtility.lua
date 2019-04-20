-- ColorUtility.lua
-- by Blu

-- Credits:
-- RGB <=> HSL
-- https://www.niwa.nu/2013/05/math-behind-colorspace-conversions-rgb-hsl/
-- HSV => RGB
-- https://www.rapidtables.com/convert/color/hsv-to-rgb.html
-- RGB => HSV
-- https://www.rapidtables.com/convert/color/rgb-to-hsv.html

-- Round to nearest integer
local function Round(num)
    return tonumber(string.format("%.0f", num))
end

local function Clamp(num, min, max)
    if     num < min then return min
    elseif num > max then return max
    else                  return num
    end
end

-- Lock hex hash into 6 chars
function FormatHex(hash)
    hash = string.gsub(string.lower(hash), "[g-z]", "f")
    local zeros = 6 - string.len(hash)
    
    if zeros == 0 then 
        return hash
    elseif zeros > 0 then
        return hash .. string.rep("0", zeros)
    else
        return string.sub(hash, 1, zeros - 1)
    end
end

-- Given any number, format rgb to r,g,b 
function FormatRGB(rgb)
    rgb = string.gsub(rgb, "[^0-9,.]", "")
    
    local length = string.len(rgb)

    if length > 11 then
        rgb = string.sub(rgb, 1, 11)
    end

    local comma1, comma2, comma3 = nil,nil,nil
    local r,g,b = 0,0,0

    comma1 = string.find(rgb, ",", 1)

    if comma1 ~= nil then
        r = tonumber(string.sub(rgb, 1, comma1 - 1))
        
        comma2 = string.find(rgb, ",", comma1 + 1)

        if comma2 ~= nil then
            g = tonumber(string.sub(rgb, comma1 + 1, comma2 - 1))

            comma3 = string.find(rgb, ",", comma2 + 1)

            if comma3 ~= nil then
                b = tonumber(string.sub(rgb, comma2 + 1, comma3 - 1))
            else
                b = tonumber(string.sub(rgb, comma2 + 1))
            end
        end
    else
        if length >= 3 then
            r = tonumber(string.sub(rgb, 1, 3))

            if length >= 6 then 
                g = tonumber(string.sub(rgb, 4, 6))

                if length >= 9 then 
                    b = tonumber(string.sub(rgb, 7, 9))
                elseif length >= 7 then
                    b = tonumber(string.sub(rgb, 7))
                end
            elseif length >= 4 then
                g = tonumber(string.sub(rgb, 4))
            end
        end
    end

    if r == nil then r = 0 end
    if g == nil then g = 0 end
    if b == nil then b = 0 end
        
    return Clamp(Round(r), 0, 255), Clamp(Round(g), 0, 255), Clamp(Round(b), 0, 255)
end

-- RGB are in values 255,255,255 respectively, returns hex hash as string
function RGBtoHex(r,g,b)
    return string.format("%02x", r) .. string.format("%02x", g) .. string.format("%02x", b)
end

-- hash must be a string, returns r,g,b
function HextoRGB(hash)
    return tonumber(string.sub(hash,1,2), 16), tonumber(string.sub(hash,3,4), 16), tonumber(string.sub(hash,5,6), 16)
end

-- Value in 360 degrees
function HueToRGB(value)
    -- RGB       ; Gradient ; Angle
    -- 255,0,0   ; 0        ; 360
    -- 255,0,255 ; 0.1666   ; 300
    -- 0,0,255   ; 0.3333   ; 240
    -- 0,225,255 ; 0.5      ; 180
    -- 0,255,0   ; 0.6666   ; 120
    -- 255,255,0 ; 0.8333   ; 60
    -- 255,0,0   ; 1        ; 0

    local index = math.floor(value / 60)
    local add = (value - index * 60) / 60 * 255

    if     index == 0 then return "255," .. add .. ",0"
    elseif index == 1 then return (255 - add) .. ",255,0"
    elseif index == 2 then return "0,255," .. add
    elseif index == 3 then return "0," .. (255 - add) .. ",255"
    elseif index == 4 then return add .. ",0,255"
    elseif index == 5 then return "255,0," .. (255 - add)
    else                   return "255,0,0"
    end
end

-- HSL are in values 360,100,100 respectively, returns r,g,b
function HSLtoRGB(h,s,l)
    h = h / 360
    s = s / 100
    l = l / 100

    -- No Saturation, so only grayness
    if s == 0 then
        local grayValue = l * 255
        return grayValue, grayValue, grayValue
    end

    local temp1 = 0
    -- Check Lightness
    if l < 0.5 then
        temp1 = l * (1.0 + s)
    else
        temp1 = l + s - l * s
    end

    local temp2 = 2 * l - temp1

    local wrap = function(value)
        if value > 1 then 
            return value - 1
        elseif value < 0 then
            return value + 1
        else
            return value
        end
    end

    local tempR = wrap(h + 0.333)
    local tempG = h
    local tempB = wrap(h - 0.333)

    local testAndGetValue = function(value)
        if (6 * value) < 1 then
            return temp2 + (temp1 - temp2) * 6 * value
        elseif (2 * value) < 1 then
            return temp1
        elseif (3 * value) < 2 then
            return temp2 + (temp1 - temp2) * (0.666 - value) * 6
        else
            return temp2
        end
    end
    
    return Round(testAndGetValue(tempR) * 255), Round(testAndGetValue(tempG) * 255), Round(testAndGetValue(tempB) * 255)
end

-- RGB are in values 255,255,255 respectively, returns h,s,l
function RGBtoHSL(r,g,b)
    r = r / 255
    g = g / 255
    b = b / 255

    local max = math.max(r,g,b)
    local min = math.min(r,g,b)

    local h = 0
    local s = 0
    local l = (min + max) / 2

    if min ~= max then
        if l < 0.5 then
            s = (max - min) / (max + min)
        else
            s = (max - min) / (2 - max - min)
        end

        if r == max then
            h = (g - b) / (max - min)
        elseif g == max then
            h = 2 + (b - r) / (max - min)
        else 
            h = 4 + (r - g) / (max - min)
        end

        if h < 0 then h = h + 6 end
    end

    return Round(h * 60), Round(s * 100), Round(l * 100)
end

-- HSV are in values 360,100,100 respectively, returns r,g,b
function HSVtoRGB(h,s,v)
    s = s / 100
    v = v / 100

    local c = s * v
    local x = c * (1 - math.abs((h / 60) % 2 - 1))
    local m = v - c

    local r2,g2,b2 = 0,0,0

    if     h < 60  then r2,g2,b2 = c,x,0
    elseif h < 120 then r2,g2,b2 = x,c,0
    elseif h < 180 then r2,g2,b2 = 0,c,x
    elseif h < 240 then r2,g2,b2 = 0,x,c
    elseif h < 300 then r2,g2,b2 = x,0,c
    elseif h < 360 then r2,g2,b2 = c,0,x
    end

    return Round((r2 + m) * 255), Round((g2 + m) * 255), Round((b2 + m) * 255)
end

-- RGB are in values 255,255,255 respectively, returns h,s,v
function RGBtoHSV(r,g,b)
    r = r / 255
    g = g / 255
    b = b / 255

    local max = math.max(r,g,b)
    local min = math.min(r,g,b)

    local h = 0
    local s = 0
    local v = max

    if min ~= max then
        s = (max - min) / max

        -- if v < 0.5 then
        --     s = (max - min) / (max + min)
        -- else
        --     s = (max - min) / (2 - max - min)
        -- end

        if r == max then
            h = (g - b) / (max - min)
        elseif g == max then
            h = 2 + (b - r) / (max - min)
        else 
            h = 4 + (r - g) / (max - min)
        end

        -- h is in 0..6 range
        if h < 0 then h = h + 6 end
    end

    return Round(h * 60), Round(s * 100), Round(v * 100)
end