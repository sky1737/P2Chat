#include "TCPSession.h"
#include "TCPSocket.h"

P2_NAMESPACE_BEG

TCPSession::TCPSession(TCPSocket *tcpSocket):
    Task(tcpSocket),
    fTCPSocket(tcpSocket)
{
    this->SetTaskName("TCPSession");
}


TCPSession::~TCPSession()
{
}

int64 TCPSession::Run()
{
    Task::EventFlags eventbits = this->GetEventFlags();
    if (eventbits & kKillEvent)
        return -1;
    else if (eventbits & kCloseEvent)
    {
        fTCPSocket->SetConnectionClose();
        if (TCPSESSION_DEBUG)
            log_debug("TCPSession::Run �Ͽ�����%s:%d\n", fTCPSocket->GetRemoteIP().c_str(), fTCPSocket->GetRemotePort());

        SetDeleteEventWhenAllRefTasksFinished(TRUE);

        return -1;
    }
    else if (eventbits & kReadEvent)
    {
        if (!fTCPSocket->IsConnectionClosed())
        {
            char buffer[1024], reply[1124];
            int32 recvSize = 0;
            Address remoteAddress = fTCPSocket->GetRemoteAddress();
            while (recvSize != -1)
            {
                ::memset(buffer, 0, sizeof(buffer));
                recvSize = fTCPSocket->Recv(buffer, 1500);
                if (recvSize != -1)
                {
                    //printf("�յ�����%s:%u������: [%dB] %s\n", remoteAddress.GetIP().c_str(), remoteAddress.GetPort(), recvSize, buffer);
                    sprintf_s(reply, "Hello, received data: %s\n", buffer);
                    fTCPSocket->Send(reply, strlen(reply));
                }
            }
            fTCPSocket->RequestEvent(EV_RE);
        }
        return -1;
    }
    else 
    {
        if (TCPSESSION_DEBUG)
            log_debug("TCPSession::Run δ�������¼�����(0x%x)\n", eventbits);
        return -1;
    }
    return -1;
}

P2_NAMESPACE_END
