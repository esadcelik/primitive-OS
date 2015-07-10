//
//  main.c
//  pofm
//
//  Created by Esad on 4/17/15.
//  Copyright (c) 2015 Esad. All rights reserved.
//

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct commands
{
    const char pofm[2000];  // String to hold help text
    const char crt[2000];  // String to hold help text
    const char del[2000];  // String to hold help text
    const char rnm[2000];  // String to hold help text
    const char cpy[2000];  // String to hold help text
    const char mov[2000];  // String to hold help text
    const char txt_apd[2000];  // String to hold help text
    const char txt_ins[2000];  // String to hold help text
    const char txt_rm[2000];  // String to hold help text
    const char txt_rd[2000];  // String to hold help text
};


static const struct commands helps = // Structure to hold content of help text

{
    
    {"\n\n\033[1m - Portable File Manager - \033[0m\n\n\nBuilt by Ibrahim El Nehal & Muhammed Esad Celik\n\n\nAvailable Commands\n\n crt [filename]... creates files\n\n del [filename]... deletes files\n\n rnm [filename] [new filename]... renames files\n\n cpy [filename] [filename copied to]... copies files\n\n move [filename] [destination]... moves files\n\n txt_apd [filename] [text]... appends text at the end of the files\n\n txt_ins [filename] [position] [text]... inserts text to specific position in files\n\n txt_rm [filename]... removes content of the files\n\n txt_rd [filename] [number of lines]... displays specified number of lines of the files\n\n [command] --help... displays help\n\nSEE ALSO\n\n The full documentation for pofm is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n crt - creates files\n\nSYNOPSIS\n\n \033[1mcrt [filename]...\033[0m\n\nDESCRIPTION\n\n Create the FILE(ies), if they do not already exist.\n\n --help displays help\n\nEXAMPLE\n\n crt example.txt\n\nSEE ALSO\n\n The full documentation for crt is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n del - deletes files\n\nSYNOPSIS\n\n \033[1mdel [filename]...\033[0m\n\nDESCRIPTION\n\n deletes the FILE(ies), if they exist.\n\n --help displays help\n\nEXAMPLE\n\n del example.txt\n\nSEE ALSO\n\n The full documentation for del is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n rnm - renames files\n\nSYNOPSIS\n\n \033[1mrnm [filename] [new filename]...\033[0m\n\nDESCRIPTION\n\n renames the FILE(ies), if new filename do not already exist.\n\n --help displays help\n\nEXAMPLE\n\n rename example.txt example2.txt\n\nSEE ALSO\n\n The full documentation for rnm is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n cpy - copies files\n\nSYNOPSIS\n\n \033[1mcpy [filename] [filename copied to]...\033[0m\n\nDESCRIPTION\n\n Copies the FILE(ies), if filename copied to do not already exist.\n\n --help displays help\n\nEXAMPLE\n\n cpy example.txt\n\nSEE ALSO\n\n The full documentation for cpy is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n mov - moves files\n\nSYNOPSIS\n\n \033[1mmove [filename] [path to destination]/[filename]...\033[0m\n\nDESCRIPTION\n\n Move the FILE(ies), if in target destination filename do not already exist.\n\n --help displays help\n\nEXAMPLE\n\n mov example.txt ../example.txt\n\n mov example.txt folder/example.txt\n\nSEE ALSO\n\n The full documentation for mov is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n txt_apd - appends text at the end of the files\n\nSYNOPSIS\n\n \033[1mtxt_apd [filename] [text]...\033[0m\n\nDESCRIPTION\n\n Appends text at the end of the FILE(ies)\n\n --help displays help\n\nEXAMPLE\n\n txt_apd example.txt text\n\n txt_apd example.txt \"text test2\"\n\nSEE ALSO\n\n The full documentation for txt_apd is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n txt_ins - Inserts text to specific position in files\n\nSYNOPSIS\n\n \033[1mtxt_ins [filename] [position] [text]...\033[0m [text] - cannot start with a number\n\nDESCRIPTION\n\n Inserts text to specific position in FILE(ies), if the file is not empty.\n\n --help displays help\n\nEXAMPLE\n\n txt_ins example.txt 70 text\n txt_ins example.txt 3 \"text text2\"\n\nSEE ALSO\n\n The full documentation for txt_ins is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n txt_rm - Removes content of the files\n\nSYNOPSIS\n\n \033[1mtxt_rm [filename]...\033[0m\n\nDESCRIPTION\n\n Removes content of the FILE(ies)\n\n --help displays help\n\nEXAMPLE\n\n txt_rm example.txt\n\nSEE ALSO\n\n The full documentation for txt_rm is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"},
    {"\n\nNAME\n\n txt_rd - Displays specified number of lines of the file.\n\nSYNOPSIS\n\n \033[1mtxt_rd [filename] [number of lines]...\033[0m\n\nDESCRIPTION\n\n Displays specified number of lines of the  FILE(ies), if they are not empty.\n\n --help displays help\n\nEXAMPLE\n\n txt_rd example.txt 70 - for the next page press enter\n\nSEE ALSO\n\n The full documentation for txt_rd is maintained as a PDF manual. \n This should give you access to the complete manual.\n\n"}
};

int main(int argc, char * argv[])
{
    
    char *crt = "crt";  // String to compare with argument input
    char *del = "del";  // String to compare with argument input
    char *rnm = "rnm";  // String to compare with argument input
    char *cpy = "cpy";  // String to compare with argument input
    char *mov = "mov";  // String to compare with argument input
    char *help = "--help";  // String to compare with argument input
    char *txt_apd = "txt_apd";  // String to compare with argument input
    char *txt_ins = "txt_ins";  // String to compare with argument input
    char *txt_rm = "txt_rm";  // String to compare with argument input
    char *txt_rd = "txt_rd";  // String to compare with argument input
    
    
    if(argc == 1){printf("%s",helps.pofm);} // for ./pofm command
    if(argv[1]){
        if(strcmp(argv[1],crt) == 0){  // for ./pofm crt command
            
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.crt);}
            else if((argc < 3) || (argc > 3)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.crt);}else{
        
            FILE *file; // File pointer
            
            file = fopen(argv[2], "r"); // Opens file in read mode
            if(file == 0){
                file = fopen(argv[2], "w+");}// Opens file in write mode
            else{printf("Error: Filename already exist\n");}
                
            fclose(file); // Closes the file
        
        
        
        }}
        else if(strcmp(argv[1],del) == 0){  // for ./pofm del command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.del);}
        else if((argc < 3) || (argc > 3)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.del);}else{
            
            int status;
            status = remove(argv[2]); // Removing the file
            
            if( status == 0 ){}
            else{perror("Error");}
        
        }}
        else if(strcmp(argv[1],rnm) == 0){   // for ./pofm rnm command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.rnm);}
        else if((argc < 4) || (argc > 4)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.rnm);}else{
        
            int status;
            
            FILE *file; // File pointer
            
            file = fopen(argv[3], "r"); // Opens file in read mode
            
            if(file != 0){printf("Error: Filename already exist\n");}
            else{
                status = rename(argv[2], argv[3]); // Renames the file
                
                if(status == 0){}
                else{
                    printf("There is no such file or you don't have permission\n");}
            
            }
            fclose(file); // Closes the file
            
        }}
        else if(strcmp(argv[1],cpy) == 0){   // for ./pofm cpy command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.cpy);}
        else if((argc < 4) || (argc > 4)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.cpy);}else{
        

            char ch; // Char to be written to file
            FILE *source, *target, *t; // File pointers
            
            
            source = fopen(argv[2], "rb"); // Opens file in read mode with byte reading
            
            t = fopen(argv[3], "r"); // Opens file in read mode
            
            if(t == 0){
            
            
            if( source == 0 )
            {
                printf("There is no such file or you don't have permission\n");
                
            }
            else{
            
                
                target = fopen(argv[3], "w"); // Opens file in write mode
                
                
                if( target == 0 )
                {
                    printf("Error: Filename already exist\n");
                    exit (EXIT_FAILURE);
                }else{
                
                    while( ( ch = fgetc(source) ) != EOF ) // Iterating the characters
                        fputc(ch, target); // Writing to the file
                    
                    fclose(source); // Closes the file
                    fclose(target); // Closes the file
                
                }
            }
            }else{printf("Error: Filename already exist\n");}
            
           
            
        
        }}
        else if(strcmp(argv[1],mov) == 0){   // for ./pofm mov command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.mov);}
        else if((argc < 4) || (argc > 4)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.mov);}else{
        
            int status;
            
            FILE *source, *y;  // File pointers
            source = fopen(argv[2], "r"); // Opens file in read mode
            
            if(source != 0){
            
                y = fopen(argv[3], "r"); // Opens file in read mode
                if(y==0){
                    status = rename(argv[2], argv[3]); // Renames the file
                    fclose(source); // Closes the file
                    if(status == 0){}
                    else
                    {
                        printf("Error: Unable to move\n");
                        
                    }
                
                }else{printf("Error: Filename already exist\n");}
                
                fclose(source); // Closes the file
                
                }
            else{printf("There is no such file or you don't have permission\n");}
        
        
        }}
        else if(strcmp(argv[1],txt_apd) == 0){   // for ./pofm txt_apd command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.txt_apd);}
        else if((argc < 4) || (argc > 4)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.txt_apd);}else{
        
        
        
            FILE *file, *l;  // File pointers
            int i = 0;
            l=fopen(argv[2], "r"); // Opens file in read mode
            if(l != 0){
                fclose(l);
                file=fopen(argv[2], "a"); // Opens file in append mode
            
                
                for(i=0;argv[3][i]!='\0';i++){ // Iterating the characters
                    
                    putc(argv[3][i],file); // Writing to the file

                }
                fclose(file); // Closes the file
            }else{
                    printf("There is no such file or you don't have permission\n");
                
                }
            
        
        }}
        else if(strcmp(argv[1],txt_ins) == 0){  // for ./pofm txt_ins command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.txt_ins);}
        else if((argc < 5) || (argc > 5)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.txt_ins);}else{
        
        
            char ch; // Char to be written to file
            FILE *file;  // File pointer
            FILE *file2;  // File pointer
            
            
            if(argv[4][0] < 64){printf("Error: First character of text cannot be a number\n");}
            else{
            file = fopen(argv[2],"r"); // Opens file in read mode
            file2 = fopen("114b3136666.txt","w"); // Opens file in write mode
            
            if( file == NULL )
            {
                remove("114b3136666.txt"); // Temporary file name for intermediate step
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }
            
            int i = 0;
            while( ( ch = fgetc(file) ) != EOF ){  // Iterating the characters
                if(i == atoi(argv[3])){ // Iterates until it finds the place to be inserted
                    for(i=0;argv[4][i]!='\0';i++){ // Iterating the characters
                        
                        putc(argv[4][i],file2); // Writing to the file
                        
                    }
                    
                
                }
                fputc(ch,file2);  // Writing to the file
                i++;
                
            }
            
            fclose(file); // Closes the file
            
            remove(argv[2]);  // Removing original file
            rename("114b3136666.txt", argv[2]); // Renaming temporary file
            fclose(file2); // Closes the file
            }
        
        }}
        else if(strcmp(argv[1],txt_rm) == 0){   // for ./pofm txt_rm command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.txt_rm);}
        else if((argc < 3) || (argc > 3)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.txt_rm);}else{
            
            FILE *file;  // File pointer
            file = fopen(argv[2],"r"); // Opens file in read mode
            
            if( file == NULL )
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }else{fclose(file);} // Closes the file

            fclose(fopen(argv[2], "w")); // Opens file in write mode
        
        }}
        else if(strcmp(argv[1],txt_rd) == 0){  // for ./pofm txt_rd command
            
            if(argv[2] && strcmp(argv[2],help) == 0){printf("\n %s \n",helps.txt_rd);}
        else if((argc < 4) || (argc > 4)){printf("\033[1mInvalid usage see manual:\033[0m \n %s \n",helps.txt_rd);}else{
        
        
            FILE *file; // File pointer
            char buf[256]; // hold buffer to be printed
            int i = 0;
            int c;  // input variable for next page
            
            if(atoi(argv[3]) <= 0){printf("Error: Number cannot be equal or less than 0\n");}
            else{
            file = fopen(argv[2], "r"); // Opens file in read mode
            if( file == NULL )
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }else{
            
            
            while (fgets (buf, sizeof(buf), file)) {   // Iterating the content
                if(i % atoi(argv[3]) == 0){ // Pauses iteration
                    c = getchar();
                    
                    }
                printf("%s", buf); // displays on command line
                i++;
            }
        
            fclose(file); // Closes the file
            }}
        }}
        else {printf("\033[1mInvalid command usage see available commands:\033[0m \n %s \n",helps.pofm);}
        
    }
    
    
   
}

