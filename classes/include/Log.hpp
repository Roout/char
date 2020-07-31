#ifndef SIMPLE_LOG_HPP
#define SIMPLE_LOG_HPP

#include <fstream>
#include <chrono>

enum class LogType {
    error,
    warning,
    info
};

// The most simple logging mechanism
class Log final { 
public:

    Log(const char* filename) {
        m_os.open(filename, std::ofstream::out);
    }

    ~Log() {
        if(m_os.is_open()) {
            m_os.close();
        }
    }
    
    template<class ...Args>
    void Write(const LogType type, Args &&... args) {
        const auto now = std::chrono::high_resolution_clock::now();
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()
        );
        m_os << ms.count() << ' ';
        switch(type) {
            case LogType::info: {
                m_os << "--info: ";
            } break;
            case LogType::error: {
                m_os << "--error: ";
            } break;
            case LogType::warning: {
                m_os << "--warning: ";
            } break;
            default: break;
        }
        ((m_os << " " << std::forward<Args>(args)), ...);
    }

private:
    std::ofstream m_os {};
};

#endif // SIMPLE_LOG_HPP
