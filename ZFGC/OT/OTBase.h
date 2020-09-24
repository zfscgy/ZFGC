#include <string>
#include <vector>

namespace ZFGC
{
	class OTSender
	{
	private:
		vector<std::string> messages;
	public:
		OTSender();
		~OTSender();
		OTSender(std::string _msg1, std::string _msg2);
		void AddMessage(std::string);
	};

	class OTReceiver
	{

	};
}