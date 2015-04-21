//functions

#include <iostream> 
#include <string>

int update_pricelist ()
{	
	int ans;
	std::cout << "Do you want to change item prices since previous "
		<< "run of program? Enter 1: yes or 2: no" << std::endl;
			std::cin >> ans; 

	return ans; 
}

