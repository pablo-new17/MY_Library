#ifndef DEBUG_MESSAGE_H
#define DEBUG_MESSAGE_H

#include <QObject>
#include <QString>
#include <QtMessageHandler>
#include <QMessageLogContext>


class Debug_Message
{
	Q_CLASSINFO("作者", "Pablo Lee")
	Q_CLASSINFO("描述", "Redirect Debug message into file")
	Q_CLASSINFO("版本號碼", "1.0.1.20171101")

private:
	//QT debug message call back function prototype
	static void	Log_Message_To_File(QtMsgType type, const QMessageLogContext& context, const QString& msg);

public:
	static QString	Log_Filename;	//This property contains the file name of log message to redirected to
	static quint32	Log_File_Size;	//This property contains the Max file size

	explicit	Debug_Message();
	explicit	Debug_Message(const QString Filename);
	explicit	Debug_Message(const QString Filename, const quint32 File_Size);
};
#endif // DEBUG_MESSAGE_H
