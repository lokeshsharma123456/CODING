#include<bits/stdc++.h>
using namespace std;

#define ll long long int

long long int minIncrements(vector<int> arr, int N)
{
	unordered_map<int, int>mp;
	long long int sum = 0;
	// sort(arr.begin(), arr.end());
	int count_reaches = 0;
	for (auto val : arr)
	{
		if (!mp[val])
			mp[val] ++;
		else
		{
			while (mp[val] != 0 )
			{
				val++;
				sum++;
			}
			mp[val]++;
		}

	}
	for (auto val : mp)
		cout << val.first << " " << val.second << endl;
	cout << endl;
	return sum;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		arr[i] = k;
	}
	// for (auto val : arr)
	// 	cout << val << " ";
	// cout << endl;
	cout << minIncrements(arr, n);


	return 0;
}


while True:
print_prompt()
	ftp_host_name = input("Host Name = ")
	                ftp_host_port = int(input("Port = "))

# create an FTP client instance, with timeout = 20 seconds
	                                ftp = ftplib.FTP(timeout = 20)

# connect to FTP server --> catch connection refused error
	                                      ftp.connect(ftp_host_name, ftp_host_port)
	                                      print("Connection established ...... \n")

# login with credentials --> catch bad credentials
	                                      ftp_user_name = input("Username = ")
	                                              ftp_user_pass = input("Password = ")
	                                                      ftp.login(ftp_user_name, ftp_user_pass)
	                                                      print("Login successful\n")

# ftp_path should be absolute path
	                                                      ftp_path = input("Enter path = ")

# Do something
                                                              try:
		                                                              ftp.cwd(ftp_path)
                                                              except ftplib.error_perm as error:
		                                                              if str(error).startswith("550"):
# separate out the file_name & dir_path to file name
				                                                              file_name = os.path.basename(ftp_path)
				                                                                      file_dir_path = os.path.dirname(ftp_path)

				                                                                              ftp.cwd(file_dir_path)
				                                                                              ftp.retrbinary("RETR {}".format(file_name), print)
# print("Print the contents of file")
                                                                              else:
					                                                                              ftp.dir()

					                                                                              ftp.quit()
					                                                                              i = 0
                                                                                      while i == 0 :
					                                                                                      ftp_path = input("Enter path = ")
                                                                                              try:
							                                                                                              ftp.cwd(ftp_path)
                                                                                              except ftplib.error_perm as error:
							                                                                                              if str(error).startswith("550"):
# separate out the file_name & dir_path to file name
								                                                                                              file_name = os.path.basename(ftp_path)
								                                                                                                      file_dir_path = os.path.dirname(ftp_path)

								                                                                                                              ftp.cwd(file_dir_path)
								                                                                                                              ftp.retrbinary("RETR {}".format(file_name), print)
# print("Print the contents of file")
                                                                                                              else:
									                                                                                                              ftp.dir()




									                                                                                                              import ftplib
									                                                                                                              import sys

									                                                                                                              def getFile(ftp, filename):
                                                                                                              try:
										                                                                                                              ftp.retrbinary("RETR " + filename , open(filename, 'wb').write)
                                                                                                              except:
										                                                                                                              print ("Error")


										                                                                                                              ftp = ftplib.FTP("ftp.nluug.nl")
										                                                                                                                      ftp.login("anonymous", "ftplib-example-1")
										                                                                                                                      data = []
										                                                                                                                              ftp.cwd('/pub/')
										                                                                                                                              ftp.dir(data.append)


                                                                                                                              for line in data :
										                                                                                                                              print ("-", line)
											                                                                                                                              getFile(ftp, 'README.nluug')

											                                                                                                                              ftp.quit()

# ftpHost = 'ftp.dlptest.com'
# # ftpPort = 2121
# ftpUname = 'dlpuser'
# ftpPass = 'rNrKYTX9g7z3RgJRmxWuGHbeu'

