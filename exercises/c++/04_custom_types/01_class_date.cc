#include <iostream>

// scoped enum for months
enum class months {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class date {

	// default class variables are private
	int _day;
	months _month;
  	int _year;
  	
	public:
	date(const int day, 
		 const months month, 
		 const int year);
		 
	int day() const {return _day;}	
	months month() const {return _month;}
	int year() const {return _year;}
		
	void print() const {
		day(); month(); year();
    	std::cout << _day << "/" << static_cast<int>(_month) << "/" << _year << std::endl;}
    	// prints the date
			
	void add_days(int n){
		day(); month(); year();
		for (auto i = 0; i < n; i++)
			add_day();}	
			
	void sub_days(int n){
		day(); month(); year();
		for (auto i = 0; i < -n; i++)
			sub_day();}
					
	private:
	void add_day();
	void sub_day();
		
};

date::date(const int day, 
		   const months month, 
		   const int year)
		   
	: _day(day), _month(month), _year(year){}
	// constructor
	
void date::add_day(){
		day(); month(); year();
		
		switch(_day){
		case 28:
			switch(_month){
			case months::feb: 
				_day = 1; _month = months::mar; break;
			default: 
				_day += 1; break;}
			break;
			
		case 30:
			switch(_month){	
			case months::apr: 
				_day = 1; _month = months::may; break;
			case months::jun:
				_day = 1; _month = months::jul; break;
			case months::sep:
				_day = 1; _month = months::oct; break;
			case months::nov: 
				_day = 1; _month = months::dec;	break;
			default:
				_day += 1; break;}
			break;
					
		case 31:
			switch(_month){
			case months::jan:
				_day = 1; _month = months::feb; break;
			case months::mar: 
				_day = 1; _month = months::apr; break;
			case months::may:
				_day = 1; _month = months::jun; break;
			case months::jul:
				_day = 1; _month = months::aug; break;
			case months::aug:
				_day = 1; _month = months::sep; break;
			case months::oct:
				_day = 1; _month = months::nov; break;
			case months::dec:
				_day = 1; _year += 1; _month = months::jan; break;
			default: 
				_day += 1; break;}
			break;
				
		default:
			_day += 1;}}
			// adds one day
			
void date::sub_day(){
		day(); month(); year();
		
		switch(_day){
		case 1:
			switch(_month){
				case months::dec:
					_day = 30; _month = months::nov; break;
				case months::nov:
					_day = 31; _month = months::oct; break;
				case months::oct:
					_day = 30; _month = months::sep; break;
				case months::sep:
					_day = 31; _month = months::aug; break;
				case months::aug:
					_day = 31; _month = months::jul; break;
				case months::jul:
					_day = 30; _month = months::jun; break;
				case months::jun:
					_day = 31; _month = months::may; break;
				case months::may:
					_day = 30; _month = months::apr; break;
				case months::apr:
					_day = 31; _month = months::mar; break;
				case months::mar:
					_day = 28; _month = months::feb; break;
				case months::feb:
					_day = 31; _month = months::jan; break;
				case months::jan:
					_day = 31; _year -= 1; _month = months::dec; break;}
			break;
			
		default: 
			_day -= 1;}}
			// subtracts one day

int main() {

	int day{4};
	months month{months::mar};
	int year{1943};
	// test date
	
  	date date(day, month, year);
  	std::cout << "Current date: ";
  	date.print();
  	
  	int n{0};
  	std::cout << "Insert a number of days: ";
	std::cin >> n;
	// if negative goes back in time
	
	if(n >= 0){
  		date.add_days(n);
  		std::cout << "Forward date: ";
		date.print();
  	}else{ 
  		date.sub_days(n);
  		std::cout << "Backward date: ";
  		date.print();}
  		// leap years are neglected
  		
  return 0;
}