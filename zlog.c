#include <stdio.h>
#include <stdarg.h>

#define OPEN_LOG 1
#define LOG_LEVEL LOG_DEBUG
#define EMLog(level,fmt,...) EM_LOG(level,_FUNCTION_,_LINE_,fmt)

typedef enum
{
	LOG_DEBUG = 0,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
}E_LOGLEVEL;

char* EM_LOGLevelGet(const int level)
{
	if (level == LOG_DEBUG)
	{
		return "DEBUG";
	}else if (level == LOG_INFO)
	{
		return "INFO";
	}
	else if (level == LOG_WARN)
	{
		return "LOG_WARN";
	}
	else if (level == LOG_ERROR)
	{
		return "LOG_ERROR";
	}
	return "UNKNOW";
}

void EM_LOG(const int level,const char* fun,const int line,const char* fmt, ...)
{
	#ifdef OPEN_LOG
	va_list arg;
	va_start(arg, fmt);
	char buf[1+ vsnprintf(NULL, 0, fmt, arg)];
	vsnprintf(buf,sizeof(buf),fmt,arg);
	va_end(arg);
	if(level >= LOG_LEVEL)
	printf("[%s] [%s %d] %s\n", EM_LOGLevelGet(level),fun,line,buf);
	#endif
}

void main()
{
	int a = 10, b = 11;
	EMLog(LOG_DEBUG, "app start");
	EMLog(LOG_INFO, "A = %d",a);
	EMLog(LOG_WARN, "app LOG_WARN");
	EMLog(LOG_ERROR, "app LOG_ERROR");
}