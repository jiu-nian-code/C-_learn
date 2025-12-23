#include"contact.h"

int main()

{
	int input = 0;
	Contact con;
	init(&con);
	do
	{
		print();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add(&con);
			break;
		case DELE:
			dele(&con);
			break;
		case RETR:
			retr(&con);
			break;
		case CHANGE:
			chan(&con);
			break;
		case SHOW:
			show(&con);
			break;
		case EMPTY:
			empt(&con);
			break;
		case SORT:
			sort(&con);
			break;
		case EXIT:
			purge(&con);
			break;
		}
	} while (input != EXIT);
	return 0;
}