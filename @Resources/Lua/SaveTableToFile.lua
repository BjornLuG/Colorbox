-- Save Table To File
-- Proudly handtyped by Blu
-- All rights of this script belongs to this source
-- https://lua-users.org/wiki/SaveTableToFile

--[[
    Save Table to File
    Load Table from File
    v 1.0

    Lua 5.2 compatible

    Only saves tables, numbers and strings
    Insides table references are saved
    Does not save Userdata, Metatables, Functions,and indices of these
    ------------------------------------------------------------------
    table.save(table,fileName)

    on failure: returns an error msg

    ------------------------------------------------------------------
    table.load(fileName or stringTable)

    Loads a table that has been saved via the Serialize function

    on success: returns a previously saved array
    on failure: returns as second argument an error msg
    ------------------------------------------------------------------

    Licensed under the same terms as Lua itself
]]--

-- For safety and hackproof
local function exportstring(s)
    return string.format("%q", s) 
end

function table.save(tbl, fileName)
    local charS, charE = "    ", "\n"
    local file, err = io.open(fileName, "wb")

    if err then return err end

    -- Initiates variables for save procedure
    local tables, lookup = { tbl }, { [tbl] = 1 }
    file:write("return {" .. charE)

    for idx,t in ipairs(tables) do
        file:write("-- Table: {" .. idx .. "}" .. charE)
        file:write("{" .. charE)
        local thandled = {}

        for i,v in ipairs(t) do
            thandled[i] = true
            local stype = type(v)
            
            -- only handle value
            if stype == "table" then
                if not lookup[v] then
                    table.insert(tables, v)
                    lookup[v] = #tables
                end
                file:write(charS .. "{" .. lookup[v] .. "}," .. charE)
            elseif stype == "string" then
                file:write(charS .. exportstring(v) .. "," .. charE)
            elseif stype == "number" then
                file:write(charS .. tostring(v) .. "," .. charE)
            end
        end

        for i,v in pairs(t) do
            -- escape handled values
            if (not thandled[i]) then
                local str = ""
                local stype = type(i)

                -- handle index
                if stype == "table" then
                    if not lookup[i] then
                        table.insert(tables, i)
                        lookup[i] = #tables
                    end
                    str = charS .. "[{" .. lookup[i] .. "}]="
                elseif stype == "string" then
                    str = charS .. "[" .. exportstring(i) .. "]="
                elseif stype == "number" then
                    str = charS .. "[" .. tostring(v) .. "]="
                end


                if str ~= "" then 
                    stype = type(v)
                    
                    -- handle value
                    if stype == "table" then
                        if not lookup[v] then
                            table.insert(tables, v)
                            lookup[v] = #tables
                        end
                        file:write(str .. "{" .. lookup[v] .. "}," .. charE)
                    elseif stype == "string" then
                        file:write(str .. exportstring(v) .. "," .. charE)
                    elseif stype == "number" then
                        file:write(str .. tostring(v) .. "," .. charE)
                    end
                end
            end
        end
        file:write("}," .. charE)
    end

    file:write("}")
    file:close()
end

function table.load(sFile)
    local fTables,err = loadfile(sFile)

    if err then return _,err end

    local tables = fTables()

    for idx = 1,#tables do
        local tolinki = {}
        for i,v in pairs(tables[idx]) do
            if type(v) == "table" then
                tables[idx][i] = tables[v[1]]
            end
            if type(i) == "table" and tables[i[1]] then
                table.insert(tolinki, {i, tables[i[1]]})
            end
        end

        -- link indices
        for _,v in ipairs(tolinki) do
            tables[idx][v[2]], tables[idx][v[1]] = tables[idx][v[1]], nil
        end
    end

    return tables[1]
end
        
