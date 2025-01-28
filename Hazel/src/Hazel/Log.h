#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <memory>

namespace Hazel{
	class Log
	{
	public:
		static HAZEL_API void Init();
		inline static HAZEL_API std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static HAZEL_API std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// �����־��Ϣʱ, ʹ�ú������Ч�ı���������
// Core log macros
#define HZ_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)	::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)	::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)	::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)	::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)	::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)	::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)	::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)	::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)

// if dist build
//�ڷַ�����ʱ���û��滻 HZ_CORE_INFO ��Ĺ��ܣ����磬����¼ INFO �������־����
//Ϊ���ڷ����汾���Ƴ���־������Ӷ�������ܻ���������������б�¶����Ҫ����Ϣ��
//���ᱩ¶�ڶ������ļ���
#define HZ_CORE_INFO

