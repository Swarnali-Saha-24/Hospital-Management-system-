#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "router.h"
#include "api.h"

void handleRequest(int clientSocket, char request[])
{
    char response[8192];

    memset(response, 0, sizeof(response));

    /* Handle browser preflight request */
    if(strstr(request, "OPTIONS /api/patient") != NULL)
    {
        strcpy(response,
        "HTTP/1.1 204 No Content\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
        "Access-Control-Allow-Headers: Content-Type\r\n"
        "Access-Control-Max-Age: 86400\r\n"
        "Connection: close\r\n"
        "\r\n");
    }

    else if(strstr(request, "POST /api/patient") != NULL)
    {
        addPatientAPI(request, response);
    }

    else if(strstr(request, "GET /api/test") != NULL)
    {
        strcpy(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
        "Access-Control-Allow-Headers: Content-Type\r\n"
        "Connection: close\r\n"
        "\r\n"
        "{\"message\":\"Backend Running Successfully\"}");
    }

    else
    {
        strcpy(response,
        "HTTP/1.1 404 Not Found\r\n"
        "Content-Type: text/plain\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
        "Access-Control-Allow-Headers: Content-Type\r\n"
        "Connection: close\r\n"
        "\r\n"
        "Route Not Found");
    }

    write(clientSocket, response, strlen(response));
}