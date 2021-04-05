
#include <iostream>
#include <random>
#include <chrono>
#include <sstream>

int ii_turn(int stone_count){
	if (stone_count==1 || stone_count==2)
		return 1;
	else if (stone_count==3)
		return 2;
	else if (stone_count==4)
		return 3;
	else if(stone_count==5)
		return 1;
	else if(stone_count==6)
			return 2;
	else return 0;
}

int read_int(const char * question)
{
			int result;
			std::string inp;
			re:std::cout<<question;
			std::getline(std::cin, inp);
			{
				std::stringstream inps{inp};
				inps >> result;
				if (inps.fail()){
					if(std::cin.fail()){
						std::cerr << "Error!" << std::endl;
						exit(1);
					}
					std::cout << "Введите число" << std::endl;
					goto re;
				}else if(not inps.eof()){
						std::cout << "Введите одну цифру" << std::endl;
						goto re;
					}
			}
			return result;
}
int menu_v=0;
int menu()
{
	menuqwe:std::cout << "Выберите сложность игры" << std::endl;
	std::cout << "1) Лёгкий" << std::endl;
	std::cout << "2) Сложный" << std::endl;
	std::cout << "0) Выйти из игры" << std::endl;
	menu_v = read_int("В итоге: ");
	switch (menu_v)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 0:
			return 0;
			break;
		default:
			std::cout << "Такого варианта нет";
			break;
		}
	goto menuqwe;
}
int main()
{

	using clk=std::chrono::system_clock;
		std::minstd_rand rnd{
			unsigned(clk::now().time_since_epoch().count())
	};
	std::cout << "Камни." << std::endl;
	menu_v=menu();
				switch (menu_v)
						{
						case 1:
							std::cout << "Лёгкий уровень"<< std::endl;
							break;
						case 2:
							std::cout << "Сложный уровень"<< std::endl;
							break;
						case 0:
							std::cout << "До встречи!"<< std::endl;
							return 0;
							break;
						default:
							std::cout << "Такого варианта нет";
							break;
						}

	nextgame:std::uniform_int_distribution <int> d{15,25};
	std::uniform_int_distribution <int> min_stone{1,3};
	unsigned stone_count = d(rnd);
	unsigned stone;



	do{
			qre:std::cout << "В кучке " << stone_count << " камней" << std::endl;
			std::cout << "Сколько возьмете? (от 1 до 3) " << std::endl;
			stone = read_int("Взять: ");
			std::cout << "Вы взяли: " << stone << std::endl;

			if(stone<=3 && stone<=stone_count && stone>=1){
				stone_count-=stone;
			}
			else{ std::cout << "Нельзя столько брать!" << std::endl;
				goto qre;}
			{
			if (stone_count==0){
				std::cout << "Проигрыш!" << std::endl;
				break;
			}
			if (menu_v==2)
				stone=ii_turn(stone_count);
			else stone=0;
			if(stone==0)
				qwe1:stone=min_stone(rnd);
			if(stone<=3 && stone<=stone_count && stone>=1){
				stone_count-=stone;
			}
			else{
				goto qwe1;
			}
			std::cout << "Бот взял " << stone << " камней" << std::endl;
			}
			if(stone_count==0){
				std::cout << "Осталось " << stone_count << " камней" << std::endl;
				std::cout << "Победа!" << std::endl;
				break;
			}
			else if(stone_count==1){
				std::cout << "Осталось " << stone_count << " камней" << std::endl;
				std::cout << "Проигрыш!" << std::endl;
				break;
			}

		} while(stone_count!=0);

		std::cout << "Ещё раз?" << std::endl;
		iim:stone = read_int("1 да, 2 нет");
		if( stone==1 || stone==2 ){
			if(stone==1)
				goto nextgame;
			else if (stone==2)
				std::cout << "Меню" << std::endl;
			menu_v=menu();
							switch (menu_v)
									{
									case 1:
										std::cout << "Лёгкий уровень"<< std::endl;
										goto nextgame;
										break;
									case 2:
										std::cout << "Сложный уровень"<< std::endl;
										goto nextgame;
										break;
									case 0:
										std::cout << "До встречи!"<< std::endl;
										return 0;
										break;
									default:
										std::cout << "Такого варианта нет";
										break;
									}

			}
		else {
			std::cout << "Такого варианта нет" << std::endl;
			goto iim;}
	return 0;
}




