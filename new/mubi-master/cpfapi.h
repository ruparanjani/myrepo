int uim_reg_usr(char *);
int svc_reg(char * );
void svcmgr_get_svc_list(char *);
/*
void sub_subscribe(char []);
void start_session(char []);
void end_session(char []);*/
char* User_Validation(char *);
int Command_Interpreter(char *);
char* getDecStr(char*,int,int);
int uid_retrive();
/*struct Uim{
	int iUid;
	char name[12];
	char mailid[25];
};
struct Svc_mgr{
	int iSid;
	char svc_name[12];	
	char svc_type[12];
	char svc_status[12];
};*/



