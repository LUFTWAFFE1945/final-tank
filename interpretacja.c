
#include "cos.h"

int decode_type(char *type)
{
    if(strcmp(type,"wall")==0){
        return 1;
    } else if(strcmp(type,"grass")==0){
        return 2;
    } else if(strcmp(type,"sand")==0){
        return 3;
    } 
    return 0;
        
}

Dane* interpret_response(const char* const chunk,Dane *w)
{
    //printf("masło4\n");
    const cJSON *payload = NULL;
    cJSON *game_json = cJSON_Parse(chunk);
    //printf("masło5\n");
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
        //printf("masło6\n");
        payload = cJSON_GetObjectItemCaseSensitive(game_json, "payload");
        //printf("masło7\n");
        cJSON *current_x = cJSON_GetObjectItemCaseSensitive(payload, "current_x");
        //printf("masło8\n");
        cJSON *list =  cJSON_GetObjectItemCaseSensitive(payload, "list");
        //printf("masło9\n");
        if(list!=NULL)
        {
            //printf("masło10\n");
                cJSON *object = NULL;
                //printf("masło11\n");
                
                cJSON* _x = NULL;
                cJSON* _y = NULL;
                cJSON* _type = NULL;

  int i;

  //cJSON *item = cJSON_GetObjectItem(list,"list");
  for (i = 0 ; i < cJSON_GetArraySize(list) ; i++)
  {
     cJSON * subitem = cJSON_GetArrayItem(list, i);
     _x = cJSON_GetObjectItem(subitem, "x");
     _y = cJSON_GetObjectItem(subitem, "y");
     _type = cJSON_GetObjectItem(subitem, "type"); 
     //printf("x[%d]=%d, y[%d]=%d, type[%d]=%d\n",i,_x->valueint,i,_y->valueint,i,decode_type(_type->valuestring));
     w->y[i]=_x->valueint;
     w->x[i]=_y->valueint;
     w->field[i] = decode_type(_type->valuestring);
     //printf("dekoduje %d \n",decode_type(_type->valuestring));
     //printf("x[%d]=%d, y[%d]=%d, type[%d]=%d\n",i,w->x[i],i,w->y[i],i,w->field[i]);
   //strcpy(w->field[i], _type->valuestring);
  }

                printf("koniec if(list...\n");
        }           
 
        else if (current_x != NULL) 
        {
            int s;
            cJSON *current_y = cJSON_GetObjectItemCaseSensitive(payload, "current_y");
            cJSON *field_type =  cJSON_GetObjectItemCaseSensitive(payload, "field_type");
            //printf("masło21\n");
            cJSON *direction =  cJSON_GetObjectItemCaseSensitive(payload, "direction");
            //printf("masło22\n");
            //printf("%d\n",current_x->valueint);
            s=current_x->valueint;
            //printf("%d\n", s);
            w->y[0]=s;//current_x->valueint;
            //rintf("masło23\n");
            w->x[0]=current_y->valueint;
            //printf("masło24\n");
            w->field[0] = decode_type(field_type->valuestring);
            //printf("masło25\n");
            w->kierunek_lufy = direction->valuestring[0];
            //printf("masło26\n");
            w->website_y = current_y->valueint;
            //printf("masło27\n");
            w->website_x = current_x->valueint;
            //printf("masło28\n");
           
        }
 
    }
    return w;
}