import socket

client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_sock.connect(('localhost', 9090))


client_sock.sendall(bytes(str(123), 'utf-8'))
data = client_sock.recv(1024)
data = str(data, 'utf-8')
data = int(data)

client_sock.close()
print(f"data: {data}")

