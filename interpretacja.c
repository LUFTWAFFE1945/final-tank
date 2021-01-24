
#include "cos.h"

Dane* interpret_response(const char* const chunk,Dane *dane)
{
    printf("masło4\n");
    const cJSON *payload = NULL;
    cJSON *game_json = cJSON_Parse(chunk);
    printf("masło5\n");
    if (game_json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
    }
    else 
    {
        printf("masło6\n");
        payload = cJSON_GetObjectItemCaseSensitive(game_json, "payload");
        printf("masło7\n");
        cJSON *current_x = cJSON_GetObjectItemCaseSensitive(payload, "current_x");
        printf("masło8\n");
        cJSON *list =  cJSON_GetObjectItemCaseSensitive(payload, "list");
        printf("masło9\n");
        if(list!=NULL)
        {
            printf("masło10\n");
                cJSON *object = NULL;
                printf("masło11\n");
                int i=0;
                cJSON_ArrayForEach(object,list)
                printf("masło12\n");
                {
                    cJSON *x = cJSON_GetObjectItemCaseSensitive(object, "x");
                    printf("masło13\n");
                    cJSON *y = cJSON_GetObjectItemCaseSensitive(object, "y");
                    printf("masło14\n");
                    cJSON *type = cJSON_GetObjectItemCaseSensitive(object, "type"); 
                    printf("masło15\n");
                    dane->y[i]=y->valueint;
                    printf("masło16\n");
                    dane->field[i] =(char*)malloc(sizeof(char)*strlen((type->valuestring)+1));
                    printf("masło17\n");
                    strcpy(dane->field[i], type->valuestring);
                    printf("masło18\n");
                    i++;
                }
        }           
 
        else if (current_x != NULL) 
        {
            printf("masło19\n");
            cJSON *current_y = cJSON_GetObjectItemCaseSensitive(payload, "current_y");
            printf("masło20\n");
            cJSON *field_type =  cJSON_GetObjectItemCaseSensitive(payload, "field_type");
            printf("masło21\n");
            cJSON *direction =  cJSON_GetObjectItemCaseSensitive(payload, "direction");
            printf("masło22\n");
            printf("%d\n",current_x->valueint);
            dane->x[0]=current_x->valueint;
            printf("masło23\n");
            dane->y[0]=current_y->valueint;
            printf("masło24\n");
            dane->field[0] =field_type->valuestring;
            printf("masło25\n");
            dane->kierunek_lufy = direction->valuestring;
            printf("masło26\n");
            dane->website_x = current_x->valueint;
            printf("masło27\n");
            dane->website_y = current_y->valueint;
            printf("masło28\n");
           
        }
 
    }
    return dane;
}