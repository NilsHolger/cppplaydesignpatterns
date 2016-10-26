#include "headers.h"

using namespace std;

enum class OutputFormat
{
	HTML,
	Markdown
};

struct ListStrategy
{
	virtual ~ListStrategy() = default;
	virtual void add_list_item(ostringstream& oss, const string& item) = 0;
	virtual void start(ostringstream& oss) = 0;
	virtual void end(ostringstream& oss) = 0;
};

struct MarkdownListStrategy : ListStrategy
{
	void start(ostringstream& oss) override
	{
	}

	void end(ostringstream& oss) override
	{
	}

	void add_list_item(ostringstream& oss, const string& item) override
	{
		oss << " * " << item << endl;
	}
};

struct HtmlListStrategy : ListStrategy
{
	void start(ostringstream& oss) override
	{
		oss << "<ul>" << endl;
	}

	void end(ostringstream& oss) override
	{
		oss << "</ul>" << endl;
	}

	void add_list_item(ostringstream& oss, const string& item) override
	{
		oss << "<li>" << item << "</li>" << endl;
	}
};

struct TextProcessor
{
	void clear()
	{
		oss.str("");
		oss.clear();
	}
	void append_list(const vector<string> items)
	{
		list_strategy->start(oss);
		for (auto& item : items)
			list_strategy->add_list_item(oss, item);
		list_strategy->end(oss);
	}

	void set_output_format(OutputFormat format)
	{
		switch (format)
		{
		case OutputFormat::Markdown:
			list_strategy = make_unique<MarkdownListStrategy>();
			break;
		case OutputFormat::HTML:
			list_strategy = make_unique<HtmlListStrategy>();
			break;
		default:
			throw runtime_error("unsupported strategy.");
		}
	}
	string str() const { return oss.str(); }
private:
	ostringstream oss;
	unique_ptr<ListStrategy> list_strategy;
};



auto main() -> int
{
	TextProcessor tp;
	tp.set_output_format(OutputFormat::Markdown);
	tp.append_list({ "a", "b", "c" });
	cout << tp.str() << endl;
	tp.clear();
	tp.set_output_format(OutputFormat::HTML);
	tp.append_list({ "a", "b", "c" });
	cout << tp.str() << endl;
}



