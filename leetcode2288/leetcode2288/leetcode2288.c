#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct digi_info
{
    int pos;
    int value;
    int len;
    char* str_val;
    struct digi_info* next;
}digi_info;

void print_node(digi_info start)
{
    digi_info* ptr = &start;
    
    while (ptr != NULL)
    {
        printf("%8d", ptr->pos);
        printf("%8d", ptr->value);
        printf("%8d", ptr->len);
        printf("%8s\n", ptr->str_val);
        ptr = ptr->next;
    }
        
}

void main()
{
    char* sentence = "abcd $110, efgh $2034, hijk $30.";
    int discount = 50;

    //char* discountPrices(char* sentence, int discount) {
        int digi_sum = 0;
        int i = 0;
        int digi_start = 0;
        int read = 0;
        char* sen_copy, *sen_ptr;

        digi_info start = {
            .next = NULL
        };
        digi_info *digi_ptr = &start;

       


        while (*(sentence + i) != '\0')
        {
            if (*(sentence + i) == '$')
            {
                digi_start = 1;
                digi_sum++;
                if (digi_sum > 1)
                {
                    digi_ptr->next = (digi_info*)malloc(sizeof(digi_info));
                    digi_ptr = digi_ptr->next;
                }

                digi_ptr->pos = i + 1;
                digi_ptr->len = 0;
                sscanf_s(sentence + i + 1, "%d", &(digi_ptr->value));
                digi_ptr->value = digi_ptr->value * (discount / 100.0);

                digi_ptr->next = NULL;
            }
            else if(digi_start)
            {
                if (*(sentence + i) <= '9' && *(sentence + i) >= '0')
                    digi_ptr->len++;
                else
                    digi_start = 0;
            }         
            

            i++;
        }

        digi_ptr = &start;
        while (digi_ptr != NULL)
        {
            digi_ptr->str_val = (char*)malloc(sizeof(char) * digi_ptr->len + 1);
            sprintf_s(digi_ptr->str_val, sizeof(char) * digi_ptr->len + 1, "%d", digi_ptr->value);
            digi_ptr = digi_ptr->next;
        } 

        sen_copy = (char*)malloc(sizeof(char) * (i + 1));

        

        digi_ptr = &start;
        sen_ptr = sentence;
        
        
        

        while (digi_ptr != NULL)
        {
            
            if (read == 0)
            {
                strncpy_s(sen_copy, i + 1, sen_ptr, digi_ptr->pos - read);
                               
            }
            else
            {
                strncat_s(sen_copy, i + 1, sen_ptr, digi_ptr->pos - read);
                
            }
            
            
            
            
            strncat_s(sen_copy, i + 1, digi_ptr->str_val, digi_ptr->len);

            read = digi_ptr->pos + digi_ptr->len;
            //printf("read:%d\n", read);

            sen_ptr = sentence + digi_ptr->pos + digi_ptr->len;
            digi_ptr = digi_ptr->next;
        }

        strncat_s(sen_copy, i + 1, sen_ptr, i + 1 - read);
        

        print_node(start);
        printf("%s", sen_copy);
    //}
        //strncat_s()
}

