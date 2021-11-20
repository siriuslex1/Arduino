#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#define led 2

/******************* STA 当手机 *****************************/
//设置STA网络参数
IPAddress sip(192, 168, 1, 29);   //本地IP
IPAddress sip1(192, 168, 1, 1);   //本地网关
IPAddress sip2(255, 255, 255, 0); //本地子网掩码

//设置STA
const char *ssid = "esptest";
const char *password = "12345671";
/**********************************************************/

/******************* AP 主机wifi *****************************/
IPAddress xip(192, 168, 2, 2); //下位远程IP
//设置AP网络参数
IPAddress lxip(192, 168, 2, 1);    //AP端IP
IPAddress lxip1(192, 168, 2, 1);   //AP端网关
IPAddress lxip2(255, 255, 255, 0); //AP端子网掩码

//设置AP账号密码
const char *ssid1 = "esphost";      //AP  wifi名
const char *password1 = "12345671"; //AP  wifi密码
/**********************************************************/

IPAddress Serverip(192, 168, 1, 4); //上位机远程IP

WiFiServer server(80);

int flag = 1;

char packetBuffer[255]; //收发缓冲区

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600); //初始化串口波特率
    delay(5000);          //延时5S

    WiFi.mode(WIFI_AP); //设置模式为AP+STA

    /******************* AP 当WIFI  *****************************/
    WiFi.softAPConfig(lxip, lxip1, lxip2); //设置AP网络参数
    WiFi.softAP(ssid1, password1, 1);      //设置AP账号密码
    /******************************************************************/

    // Serial.print("ap-ip:");
    // Serial.println(WiFi.softAPIP()); // AP 自己当WIFI 自己设置的内网地址

    /******************* STA 当手机连接WIFI *****************************/
    // WiFi.begin(ssid, password); //连接指定路由

    // Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
    // WiFi.config(sip, sip1, sip2); //设置本地网络参数

    // Serial.print("Is connection routing, please wait");

    // while (WiFi.status() != WL_CONNECTED) //等待路由连接
    // {
    //     delay(500);
    //     Serial.print(".");
    // }

    /******************************************************************/

    // Serial.println(" ");
    server.begin();
    // Serial.print("ip:");
    // Serial.println(WiFi.localIP()); // STA 当手机连接WIFI 自己设置的静态地址
}

void loop()
{
    // Serial.println("loop begin");
    WiFiClient client = server.available();
    if (client)
    {
        // Serial.println("\n[Client connected]");
        while (client.connected())
        {
            // read line by line what the client (web browser) is requesting
            if (client.available())
            {
                String line = client.readStringUntil('\r');
                //Serial.print(line);
                flag = 0;
                // GET /home?par=10 HTTP:1.0
                String get = parseGet(line);
                // client.println(String("HTTP/1.1 200 OK\r\n") +
                //                "Content-Type: text/html\r\n");
                //                 Serial.print(line);
                //Serial.println(get);
                APIConfig(get, client);

                if (get[1] == 'x')
                {
                    APIConfigP(get, client);
                }
                // wait for end of client's request, that is marked with an empty line
                if (line.length() == 1 && line[0] == '\n')
                {
                    client.println(prepareHtmlPage());
                    break;
                }
            }
        }
        // give the web browser time to receive the data

        // close the connection:
        client.stop();
        // Serial.println("[Client disonnected]");
        delay(100);
    }
}

String prepareHtmlPage()
{
    String htmlPage =
        String("HTTP/1.1 200 OK\r\n") +
        "Content-Type: text/html\r\n" +
        "Connection: close\r\n" + // the connection will be closed after completion of the response
        "Refresh: 5\r\n" +
        "\r\n" +
        "<!DOCTYPE HTML>" + // refresh the page automatically every 5 sec +
        "<html>" +
        "Analog input:  " + 123 +
        "</html>" + "\r\n";
    return htmlPage;
}

String parseGet(String line)
{
    int i, j = 0;
    String res = "";
    if (line[0] == 'G' && line[1] == 'E' && line[2] == 'T')
    {
        for (i = 0; i < line.length(); i++)
        {
            if (line[i] == 'H' && line[i + 1] == 'T' && line[i + 2] == 'T' && line[i + 3] == 'P')
            {
                for (j = 4; j < i - 1; j++)
                {
                    res += line[j];
                }
            }
        }
    }
    return res;
}

void APIConfig(String route, WiFiClient client)
{
    if (route == "/high")
    {
        digitalWrite(led, HIGH);
    }
    if (route == "/low")
    {
        digitalWrite(led, LOW);
    }
    if (route == "/tandh")
    {
        String result;
        Serial.print("TP");
        while (!flag)
        {
            result = UARTRead();
        }
        client.print(result);
    }
    if (route == "/ws")
    {
        String result;
        Serial.print("WS");
        while (!flag)
        {
            result = UARTRead();
        }
        client.print(result);
    }
    if (route == "/ds")
    {
        String result;
        Serial.print("DS");
        while (!flag)
        {
            result = UARTRead();
        }
        client.print(result);
    }
        if (route == "/init")
    {
        String result;
        Serial.print("INIT");
        while (!flag)
        {
            result = UARTRead();
        }
        client.print(result);
    }
}

void APIConfigP(String route, WiFiClient client)
{
    String ins = "";
    String par = "";
    if (route[2] == 's' && route[3] == 'b')
    {
        ins = "xsb";
        for (int i = 12; i < 14; i++)
        {
            par += route[i];
        }
        Serial.print(ins + par);
        String result;
        while (!flag)
        {
            result = UARTRead();
        }

        client.print(result);
    }
    if (route[2] == 'a' && route[3] == 'a')
    {
        ins = "xaa";
        for (int i = 12; i < 13; i++)
        {
            par += route[i];
        }
        Serial.print(ins + par);
        String result;
        while (!flag)
        {
            result = UARTRead();
        }

        client.print(result);
    }
    if (route[2] == 'l' && route[3] == 'c')
    {
        ins = "xlc";
        for (int i = 12; i < 15; i++)
        {
            par += route[i];
        }
        Serial.print(ins + par);
        String result;
        while (!flag)
        {
            result = UARTRead();
        }
        client.print(result);
    }
}

String UARTRead()
{
    String Msg = "";
    //---UART 接收函数---//
    while (Serial.available() > 0)
    {
        flag = 1;
        Msg += char(Serial.read());
        delay(2);
    }
    //--- END ---//
    return Msg;
}
