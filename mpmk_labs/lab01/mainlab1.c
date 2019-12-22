main(int argc, char const *argv[])
{
	int arr[16] = {1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1};
	int input;
	scanf_s("%d",input);
	if(input>=0 && input<16)
	arr[input]?printf('true'):printf('false');		
	else printf("input  >=0");
	return 0;
}