#pragma once

#include "Layer/Layer.h"
#include "Events/ApplicationEvents.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Iridescent {

	class IRID_EXPORT ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

        virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

} 
