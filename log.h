#ifndef LOG_H
#define LOG_H
#include <fstream>
#include <iostream>
#include <SFML\Graphics.hpp>
class Log
{
public:
	Log();
	~Log();

	static void wp(std::string&, bool = true);

	static void wp(const char*, bool = true);

	template <typename T>
	static void wp(sf::Vector2<T>& vec, bool repeat = true){
		std::string s = " X = " + std::to_string(vec.x) + " Y = " + std::to_string(vec.y);
		wp(s, repeat);
	}

	template <typename T>
	static void wp(const sf::Vector2<T>& vec, bool repeat = true){
		std::string s = " X = " + std::to_string(vec.x) + " Y = " + std::to_string(vec.y);
		wp(s, repeat);
	};

	template <typename T>
	static void wp(sf::Rect<T>& rect, bool repeat = true){
		std::string s = " X = " + std::to_string(rect.left) + " Y = " + std::to_string(rect.top) + " W = " + std::to_string(rect.width) + " H = " + std::to_string(rect.height);
		wp(s, repeat);
	};

	template<typename T>
	static void wp(T& data, bool = true){
		wp(std::to_string(data));
	};

	static void close();

private:
	static std::string m_lastWrite;
	static std::ofstream m_file;
};

#endif