#pragma once
#include "render.h"
#include "includes.h"
#include "functions.h"

// ported from my kernel multihack
namespace game
{
    namespace notify
    {
        static int lasttime = uiContext->realTime;
        static float deltatime = 0.0f;

        struct notify_data
        {
            const char* text;
            vec2_t pos;
            vec2_t size;
            float timer;

            notify_data(const char* t, float time)
                : text(t), timer(time)
            {
                pos = vec2_t(0.f, uiContext->screenHeight + 50.f);
                size = vec2_t(0.f, 0.f);
            }
        };

        std::vector<notify_data*> notifications;

        inline void add(const char* text, float timer = 6.f)
        {
            notifications.push_back(new notify_data(text, timer));
        }

        void clear_all()
        {
            for (size_t i = 0; i < notifications.size(); i++)
            {
                delete notifications[i];
            }

            notifications.clear();
        }

        void draw()
        {
            deltatime = (uiContext->realTime - lasttime) / 1000.0f;
            lasttime = uiContext->realTime;

            if (notifications.empty())
                return;

            float posx = uiContext->screenWidth / 2;
            float posy = uiContext->screenHeight - 25;

            size_t i = 0;
            size_t visual_idx = 0;

            while (i < notifications.size())
            {
                notify_data* notify = notifications[i];

                notify->timer -= deltatime;

                if (notify->timer <= 0.f)
                {
                    delete notify;
                    notifications.erase(notifications.begin() + i);
                    // Don't increment i; next notification is now at same index
                    continue;
                }

                float targetposx = posx;
                float targetposy = (notify->timer <= 1.f)
                    ? uiContext->screenHeight + 50.f
                    : posy - (visual_idx * 22);  // Use visual index

                float speed = (notify->timer <= 1.f) ? 4.f : 10.f;

                notify->pos.x = targetposx;
                notify->pos.y = render::lerp(notify->pos.y, targetposy, clamp(speed * deltatime, 0.0f, 1.0f));

                render::shader(
                    notify->pos.x - (render::textwidth(notify->text, normalfont) / 1) * 0.5f / 2 - 1,
                    notify->pos.y - 13 - 1,
                    2 + (render::textwidth(notify->text, normalfont) / 1) * 0.5f + 2 + 2,
                    2 + 13 + 2 + 2,
                    render::colors::accent,
                    "white"
                );

                render::shader(
                    notify->pos.x - (render::textwidth(notify->text, normalfont) / 1) * 0.5f / 2,
                    notify->pos.y - 13,
                    2 + (render::textwidth(notify->text, normalfont) / 1) * 0.5f + 2,
                    2 + 13 + 2,
                    render::colors::darkgrey,
                    "white"
                );

                render::text(
                    notify->text,
                    notify->pos.x + 2,
                    notify->pos.y + 3,
                    normalfont,
                    0.5f,
                    render::colors::white,
                    false,
                    render_alignment::center
                );

                ++i;
                ++visual_idx;
            }
        }
    }
}