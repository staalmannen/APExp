#include <stdio.h>
#include <stdlib.h>
#include <task.h>
#include <Task.h>

#define		VALUE	0
#define		ERROR	(-1)

#define		PLUS	0
#define		MINUS	1

class Message : public object
{
public:
	int	r_op;
	int	r_arg1;
	int	r_arg2;
	qtail*	r_reply;
};

class Server : public task {
public:
	Server(qhead*);
};

Server::Server(qhead* in) : task("Server", SHARED, 3000)
{
	INIT_TASK();

	for (;;) {
		Message*	req = (Message*) in->get();
		qtail*		reply = req->r_reply;
		int		res = VALUE;
		int		val;

		switch (req->r_op) {
		case PLUS:
			val = req->r_arg1 + req->r_arg2;
			break;
		case MINUS:
			val = req->r_arg1 - req->r_arg2;
			break;
		default:
			res = ERROR;
		}
		req->r_op = res;
		req->r_arg1 = val;
		reply->put(req);
	} 
}

void
main()
{
	qtail*	rq = new qtail;
	Server*	ser;

	NEW_TASK(ser, Server(rq->head()));

	qhead	*rply = new qhead;
	qtail*	rply_to = rply->tail();
	Message*	mess = new Message;

	mess->r_op = PLUS;
	mess->r_arg1 = 1;
	mess->r_arg2 = 2;
	mess->r_reply = rply_to;

	rq->put(mess);
	mess = (Message*)rply->get();
	if (mess->r_op == ERROR) {
		printf("ERROR\n");
	}
	printf("1 + 2 = %d\n", mess->r_arg1);
	exit(0);
}
