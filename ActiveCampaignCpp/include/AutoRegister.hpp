#ifndef AUTOREGISTER_HPP
#define AUTOREGISTER_HPP

template <typename T>
class AutoRegister
{
protected:
	static bool s_bRegistered;
};

template <typename T>
bool AutoRegister<T>::s_bRegistered = ActiveCampaignFactory::Register(T::GetFactoryName(), T::CreateMethod);

#endif