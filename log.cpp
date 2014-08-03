#include "log.h"

std::string Log::m_lastWrite;
std::ofstream Log::m_file("log.txt");
void Log::wp(std::string& s, bool repeat){
	wp(s.c_str(), repeat);
}

void Log::wp(const char* s, bool repeat){
	if (m_file){
		if (repeat){
			m_file << s << std::endl;
			std::cout << s << std::endl;
		}
		else{
			if (m_lastWrite != s){
				m_file << s << std::endl;
				std::cout << s << std::endl;
				m_lastWrite = s;
			}
		}
	}
	else
		std::cout << "le fichier n'est pas ouvert !" << std::endl;
}
void Log::close(){
	m_file.close();
}
