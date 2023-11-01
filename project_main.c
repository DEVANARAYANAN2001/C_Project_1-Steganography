#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"
#include <string.h>
/*
NAME : R DEVANARAYANAN 
DATE : 27 aug 2023
PROJECT NAME : STEGANOGRAPHY
PROJECT INPUT : MAGIC STRINGS , SECRET MESSAGE , .bmp IMAGE.
PROJECT OUTPUT : OUTPUT.bmp IMAGE ,OUTPUT.txt FILE.
*/
int main(int argc,char*argv[])
{
    EncodeInfo encInfo;          //Encode structure
    DecodeInfo decInfo;          //Decode structure

    // Fill with sample filenames
    encInfo.src_image_fname = argv[2];
    encInfo.secret_fname = argv[3];
    encInfo.stego_image_fname = "stego_img.bmp";

    //////////////////////
    int var1 = check_operation_type(argv);   //to check the operation are encode or not
    if(var1 == 0)
    {
	if(argc >= 4)                   
	{
	    read_and_validate_encode_args(argv,&encInfo);  //this function are used to the user given file are suitable file or not
	    int var2 = do_encoding(&encInfo);     //do encoding function calling 
	    if(var2 == e_success)                       //to check do_encoding function return e_success or not
	    {
		printf("Encoding success\n");          //the do encoding return e_success the encoding part perform good
	    }
	    if(var2 == e_failure)
	    {
		printf("Encoding failure\n");
	    }
	}
	else
	{
	    printf("Invalid number of arguments\n");          //less than four argument user will give  the error message will print
	}
    }
    else if(var1 == 1)                  
    {
	if(argc >= 3)
	{
	    read_and_validate_decode_args(argv,&decInfo);  //this function are used to the user given file are not suitable file or not
	    int var3 = do_decoding(&decInfo);
	    if(var3 == e_success)                     //the do_decoding funtion 
	    {
		printf("Decoding success\n");
	    }
	    if(var3 == e_failure)
	    {
		printf("Decoding failure\n");
	    }
	}

	else
	{
	    printf("Invalid number of arguments\n");     //less than three argument user will give the error message will print
	}
    }
    else
    {
	printf("Unsupported\n");                      //the operation are not decode and encode the error message will print
    }

    return 0;
}
