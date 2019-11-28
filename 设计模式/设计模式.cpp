// 设计模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>

int main()
{
	std::list< int> List;
	List.push_back(1);
	List.push_back(12);
	List.push_back(13);

	// std::list< int>::iterator itList;
	// for ( auto value : List)
	// {
	// 	// itList = List.begin();
	// 	std::cout << value << std::endl;;
	// 	if (value==12)
	// 	{
	// 		List.erase()
	// 	}
	// 	std::cout << value << std::endl;;
	// }
	std::list< int>::iterator itList;
	itList = List.end();
	for (auto it = List.begin(); it!= List.end();++it )
	{
		
		if (*it ==15)
		{
			itList = it;
			break;
		}
		
		// std::cout << *it << std::endl;
	}
	if (itList!=List.end())
	{
		List.erase(itList);
	}
	
	for (auto value : List)
	{
		std::cout << value << std::endl;
	}
	std::cout << List.size()<<std::endl;


	auto mem = std::find(List.begin(), List.end(), 19);
	if (mem==List.end())
	{
		std::cout << "没有找到" << std::endl;
	}
	else
	{
		std::cout << "找到" << std::endl;
		
	}
   
}


