#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QStringList>

#include "Debug_Message.h"

// ===================================================================================
// Private Method
//redirect to file
void Debug_Message::Log_Message_To_File(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	if(Debug_Message::Log_Filename.isEmpty())
	{
		Debug_Message::Log_Filename = QString("stdout");
	}
	else
	{
		QFileInfo	LogFile(Debug_Message::Log_Filename);
		if(LogFile.size() > Debug_Message::Log_File_Size)
		{
			QString		Backup_Filename = QString(Debug_Message::Log_Filename).append(".old");
			QFileInfo	Backup(Backup_Filename);

			if(Backup.exists())	QFile::remove(Backup_Filename);
			QFile::rename(Debug_Message::Log_Filename, Backup_Filename);
		}
	}

	QFile Log(Debug_Message::Log_Filename);
	QString Date_Time = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
	QFileInfo File(QString(context.file));
	QString Function_Name = QString(context.function).split("::").last();
	QString Code_Infomation = QString("(%1,%2)#%3").arg(File.baseName()).arg(Function_Name).arg(context.line);
	QString Message_Level;

	switch (type)
	{
	case QtDebugMsg:
		Message_Level ="DEBUG";
		break;
	case QtInfoMsg:
		Message_Level ="INFO";
		break;
	case QtWarningMsg:
		Message_Level ="WARN";
		break;
	case QtCriticalMsg:
		Message_Level ="ERROR";
		break;
	case QtFatalMsg:
		Message_Level ="FATAL";
		break;
	}

	QString Total = QString("%1 [%2%3]:%4\n").arg(Date_Time).arg(Message_Level).arg(Code_Infomation).arg(msg.trimmed());
	if(Log.open(QFile::Append | QFile::Text)==true)
	{
		if(Log.isWritable())
		{
			Log.write(Total.toStdString().c_str());
		}
		Log.close();
	}
	if(type==QtFatalMsg)
		abort();
}

// ===================================================================================
// Grobal Area
QString Debug_Message::Log_Filename = "/tmp/debug.message";
quint32 Debug_Message::Log_File_Size = 300 * 1024;

// ===================================================================================
// Constructor
Debug_Message::Debug_Message()
{
	qInstallMessageHandler(Debug_Message::Log_Message_To_File);
}
Debug_Message::Debug_Message(const QString Filename)
{
	Debug_Message::Log_Filename = Filename;
	qInstallMessageHandler(Debug_Message::Log_Message_To_File);
}
Debug_Message::Debug_Message(const QString Filename, const quint32 File_Size)
{
	Debug_Message::Log_Filename = Filename;
	Debug_Message::Log_File_Size = File_Size;
	qInstallMessageHandler(Debug_Message::Log_Message_To_File);
}
