#include <stdio.h>
#include <stdlib.h>

struct node *head;

struct node {
    int data;
    struct node* next;
};

void awal()
{
    struct node *ptr;
    int data;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL)
    {
        printf("Overflow!");
    }
    else
    {
        printf("Masukan Batas Angka Awal : ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        printf("\nAngka Batas Awal Berhasil Terinput...");
    }
}
void clrawal(){
     struct node *ptr;
    if(head == NULL)
    {
        printf("\nList kosong bro!\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nBatas Angka Awal Berhasil Terhapus...");
        getch();
    }
}
void clrakhir()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("Belum Ada Batas Angka Akhir...");
    }
    else
    {
        ptr->next = head;
            head = ptr; free(ptr);
            printf ("\nBatas Akhir Berhasil Terhapus...");

    }
}
void akhir()
{
    struct node *ptr, *temp;
    int data;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL)
    {
        printf("Overflow!");
    }
    else
    {
        printf("Input Batas Angka Akhir : ");
        scanf("%d", &data);
        ptr->data = data;
        if(head==NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("Angka Berhasil Tersimpan...\n");
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Angka Batas Akhir Dapat Tersimpan...\n");
        }
    }

}

void bebas()
{
    struct node *ptr, *temp;
    int data, loc, i;

    ptr = (struct node*) malloc(sizeof(struct node*));
    if (ptr==NULL)
    {
        printf("Overflow!");
    }
    else
    {
        printf("Input Angka : ");
        scanf("%d", &data);
        ptr->data = data;
        printf("Sisipkan Dalam List Keberapa ? : ");
        scanf("%d", &loc);
        temp = head;
        for(i=0; i<loc; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                printf("Data Tidak Dapat Tersimpan...");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Angka Berhasil Tersimpan...\n");
    }

}
void clrbebas(){
    system("cls");
    struct node *ptr,*temp,*temp2;
    char *data1;
    if(head == NULL){
        printf("Belum Ada List Terinput...");
    }else{
        if (head->next != NULL) {
            temp = head;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            ptr = temp->next;
            data1 = ptr->data;
            temp->next = NULL;
            free(ptr);
        } else {
            data1 = head->data;
            head = NULL;
        }
        printf("Angka Bebas Berhasil Dihapus...");
    }
}

void cetak()
{
    struct node *ptr;
   // int data,i=0,flag;
    ptr = head;
    if(ptr==NULL)
    {
        printf("Belum Ada Data Terinput Dalam List...");
    }
    else
    {
        printf("Cetak Isi List .... ");
        while(ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}


int main()
{
   int pilihan = 0;


   while(pilihan != 6 )
   {
       system("cls");
       printf("\n ----------------------------------------");
       printf("\n             LINKED LIST ANGKA");
       printf("\n ----------------------------------------\n\n");
       printf(" 1. Input Batas Angka Awal  \n");
       printf(" 2. Input Batas Angka Akhir \n");
       printf(" 3. Input Angka Bebas \n");
       printf(" 4. Check List Input \n");
       printf(" 5. Hapus Angka Awal \n");
       printf(" 6. Hapus Angka Akhir \n");
       printf(" 7. Hapus Angka Bebas \n");
       printf(" 8. Keluar \n");
       printf("\n    ________________\n");
       printf("    Masukan Pilihan : ");
       scanf("%d", &pilihan);

       switch(pilihan)
       {
           case 1 :
               {
                   system("cls");
                   awal();
                   getch();
                   break;
               }



           case 2 :
               {
                  system("cls");
                  akhir();
                  getch();
                  break;
               }



           case 3 :
               {
                   system("cls");
                   bebas();
                   getch();
                   break;
               }


           case 4 :
               {
                   system("cls");
                   cetak();
                   getch();
                   break;
               }


           case 5 :
               {
                   system("cls");
                   clrawal();
                   break;
               }


           case 6 :
               {
                   system("cls");
                   clrakhir();
                   break;

               }

           case 7 :
               {
                   system("cls");
                   clrbebas();
                   break;
               }


           case 8 :
               exit(0);
           break;

           default:
           printf("Pilihan Anda Salah");
       }

   }
}
