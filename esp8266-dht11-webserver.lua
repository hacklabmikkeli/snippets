-- with a little help from liste

if srv then srv:close() end
srv=net.createServer(net.TCP) 
srv:listen(80,function(conn) 
    conn:on("receive",function(conn,payload)
        print(payload)
        conn:send("HTTP/1.1 200 OK\r\n"
                 .. "Content-type: text/plain\r\n"
                 .. "Connection: close\r\n"
                 .. "\r\n",
            function ()
                pin = 4
                status, temp, humi = dht.read(pin)
                conn:send("status: " .. status .. "\r\n"
                          .. "temp: " .. temp .. "\r\n"
                          .. "humi: ".. humi .. "\r\n\r\n",            
                    function()
                        conn:close()
                    end)
            end)
   end)
end)
