// Project UID c1f28c309e55405daf00c565d57ff9ad
#include <iostream>
#include <string>
#include "json.hpp"
#include <list>
using nlohmann::json;

class OHQueue {
public:
	void GET(std::string path, int cont_len);
	void POST(std::string path, int cont_len);
	void DELETE(std::string path);
	void ERROR();
	
private:
	struct Student {
		int position;
		json in;
	};
	json out(Student pos);
	std::list<Student> queue;
};

json OHQueue::out(Student pos) {
	json ou;
	ou["location"] = pos.in["location"];
	ou["position"] = pos.position;
	ou["uniqname"] = pos.in["uniqname"];
	return ou;
}

void OHQueue::ERROR() {
	std::cout << "HTTP/1.1 400 Bad Request\n"
		<< "Content-Type: application/json; charset=utf-8\n"
		<< "Content-Length: 0\n\n";
}

void OHQueue::GET(std::string path, int cont_len) {
	if (path == "/api/") {
		json urls;
		urls["queue_head_url"] = "http://localhost/queue/head/";
		urls["queue_list_url"] = "http://localhost/queue/";
		urls["queue_tail_url"] = "http://localhost/queue/tail/";
		std::string s_urls = urls.dump(4) + "\n";
		std::cout << "HTTP/1.1 200 OK\n"
			<< "Content-Type: application/json; charset=utf-8\n"
			<< "Content-Length: 160\n\n" << s_urls;
	}
	else if (path == "/api/queue/head/" && !queue.empty()) {
		std::string body = out(*queue.begin()).dump(4) + "\n";
		std::cout << "HTTP/1.1 200 OK\n"
			<< "Content-Type: application/json; charset=utf-8\n"
			<< "Content-Length: " << body.length() << "\n\n" << body;
	}
	else if (path == "/api/queue/") {
		json body; std::string s_body;
		if (queue.empty()) {
			body["count"] = 0; body["results"] = json();
			s_body = body.dump(4) + "\n";
		}
		else {
			body["count"] = queue.size();
			for (std::list<Student>::iterator it = queue.begin(); it != queue.end(); ++it) {
				body["results"].push_back(out(*it));
			} s_body = body.dump(4) + "\n";
		}
		std::cout << "HTTP/1.1 200 OK\n"
			<< "Content-Type: application/json; charset=utf-8\n"
			<< "Content-Length: " << s_body.length() << "\n\n" << s_body;
	}
	else {
		ERROR();
	}
}

void OHQueue::POST(std::string path, int cont_len) {
	if (path == "/api/queue/tail/") {
		std::string output = "";
		if (cont_len > 0) {
			Student new_student;
			std::cin >> new_student.in;
			new_student.position = queue.size() + 1;
			queue.push_back(new_student);
			output = out(new_student).dump(4) + "\n";
			
		}
		cont_len = output.length();
		std::cout << "HTTP/1.1 201 Created\n"
			<< "Content-Type: application/json; charset=utf-8\n"
			<< "Content-Length: " << cont_len << std::endl << std::endl;
		std::cout << output;
	}
	else {
		ERROR();
	}
}

void OHQueue::DELETE(std::string path) {
	if (path == "/api/queue/head/" && !queue.empty()) {
		std::cout << "HTTP/1.1 204 No Content\n"
			<< "Content-Type: application/json; charset=utf-8\n"
			<< "Content-Length: 0\n\n";
		queue.pop_front();
		for (std::list<Student>::iterator it = queue.begin(); it != queue.end(); ++it) {
			it->position = it->position - 1;
		}
	}
	else {
		ERROR();
	}
}

int main() {
	OHQueue queue;
	std::string method, path, junk;
	int content_length;
	while (std::cin >> method >> path >> junk >> junk >> junk
		>> junk >> junk >> junk >> junk >> content_length) {
		if (method == "GET") {
			queue.GET(path, content_length);
		}
		else if (method == "POST") {
			queue.POST(path, content_length);
		}
		else if (method == "DELETE") {
			queue.DELETE(path);
		}
		else {
			queue.ERROR();
		}
	}
	return 0;
}