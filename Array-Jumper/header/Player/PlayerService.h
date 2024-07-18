#pragma 
namespace Player {
	class PlayerController;
	class PlayerService
	{
	private:
		PlayerController* playerController;

		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();
	};
}
