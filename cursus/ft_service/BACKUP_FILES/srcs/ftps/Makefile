SSL_DIR = ssl
KEY = $(addprefix $(SSL_DIR)/, vsftpd.key)
CRT = $(addprefix $(SSL_DIR)/, vsftpd.crt)

keys:
	mkdir -p $(SSL_DIR)
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj /C=KR/ST=Seoul/L=Seoul/O=42/OU=Lee/CN=ftpdsvc \
	-keyout $(KEY) -out $(CRT)

clean:
	rm -f $(KEY)
	rm -f $(CRT)

.PHONY: keys clean
