#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "api.h"
#include "patient.h"

int addPatientAPI(char request[], char response[])
{
    Patient p;

    memset(&p, 0, sizeof(Patient));

    char *body = strstr(request, "\r\n\r\n");

    if(body == NULL)
    {
        strcpy(response,
        "HTTP/1.1 400 Bad Request\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "\r\n"
        "{\"message\":\"Invalid Request\"}");

        return 0;
    }

    body += 4;

    sscanf(body,
    "{\"name\":\"%[^\"]\",\"age\":\"%d\",\"gender\":\"%[^\"]\",\"disease\":\"%[^\"]\",\"phone\":\"%[^\"]\",\"address\":\"%[^\"]\"}",
    p.name,
    &p.age,
    p.gender,
    p.disease,
    p.phone,
    p.address);

    static int id = 1;
    p.patientID = id++;

    if(savePatient(p))
    {
        strcpy(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Connection: close\r\n"
        "\r\n"
        "{\"message\":\"Patient Added Successfully\"}");
    }
    else
    {
        strcpy(response,
        "HTTP/1.1 500 Internal Server Error\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Connection: close\r\n"
        "\r\n"
        "{\"message\":\"Failed To Save Patient\"}");
    }

    return 1;
}