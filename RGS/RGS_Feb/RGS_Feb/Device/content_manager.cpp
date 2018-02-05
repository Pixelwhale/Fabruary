//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Contentを読み込むクラス
//-------------------------------------------------------
#include <Device\content_manager.h>
#include <DX\DXLib\DxLib.h>

using namespace Device;

ContentManager::ContentManager()
{
}

ContentManager::ContentManager(const ContentManager&)
{
}

ContentManager::~ContentManager()
{
}

void ContentManager::Initialize()
{
	DxLib::InitGraph();			//Memory上のテクスチャ情報を削除
	m_textures.clear();			//TextureのHandleを削除

	for (auto& map : m_motion)	//MotionHandleをDelete
	{
		delete[] map.second;
	}
	m_motion.clear();			//MotionのHandleを削除

	InitFontToHandle();			//FontのHandleを削除
	m_font.clear();

	InitShader();				//ShaderHandleを削除
	m_pixel_shader.clear();

	m_resource_manager = ss::ResourceManager::getInstance();	//SpriteStudioのContentManagerを初期化

	LoadFont("Arial", -1, -1);
	LoadFont("MS UI Gothic", -1, -1);
}

void ContentManager::Release()
{
	DxLib::InitGraph();			//Memory上のテクスチャ情報を削除
	m_textures.clear();			//TextureのHandleを削除

	for (auto& map : m_motion)	//MotionHandleをDelete
	{
		delete[] map.second;
	}
	m_motion.clear();			//MotionのHandleを削除

	InitFontToHandle();			//FontのHandleを削除
	m_font.clear();

	InitShader();				//ShaderHandleを削除
	m_pixel_shader.clear();

	if(m_resource_manager)
		delete (m_resource_manager);	//SpriteStudioのコンテンツを解放
}


#pragma region Model関連

void ContentManager::LoadModel(std::string file_name, std::string file_extention, std::string path) 
{
	int handle = MV1LoadModel((path + file_name + file_extention).c_str());
	m_models[file_name] = handle;			//ハンドル追加
}

int ContentManager::ModelHandle(std::string model_name) 
{
	return m_models[model_name];
}

#pragma endregion


#pragma region Texture関連

void ContentManager::LoadTexture(
	std::string file_name,
	std::string file_extention,
	std::string path)
{
	int handle = LoadGraph((path + file_name + file_extention).c_str());		//Textureを読み込み
	m_textures[file_name] = handle;												//HandleをMapに追加
}

void  ContentManager::LoadTexture(
	std::string file_name, std::string file_extention,
	int total, int x_count, int y_count, int x_size, int y_size,
	std::string path)
{
	int* handle = new int[total];
	int error;
	error = LoadDivGraph((path + file_name + file_extention).c_str(),
		total, x_count, y_count, x_size, y_size, handle);						//Textureを分割して読み込む
	m_motion[file_name] = handle;												//HandleをMapに追加
}

int  ContentManager::TextureHandle(std::string texture_name)
{
	return m_textures[texture_name];
}

int ContentManager::MotionHandle(std::string texture_name, int motion_index)
{
	return (m_motion[texture_name])[motion_index];
}

#pragma endregion


#pragma region Font関連

void ContentManager::LoadFont(std::string font_name, int size, int thickness) 
{
	int handle;
	handle = CreateFontToHandle(font_name.c_str(), size, thickness);
	if (handle == -1)						//Error対策
		return;
	m_font[font_name] = handle;
}

int ContentManager::FontHandle(std::string font_name) 
{
	return m_font[font_name];
}

#pragma endregion


#pragma region Shader関連

void ContentManager::LoadShaderPixel(std::string file_name, std::string file_extention, std::string path) 
{
	int handle = DxLib::LoadPixelShader((path + file_name + file_extention).c_str());
	m_pixel_shader[file_name] = handle;
}

int ContentManager::PixelShaderHandle(std::string shader_name) 
{
	return m_pixel_shader[shader_name];
}

#pragma endregion


#pragma region Sprite Studio関連

void Device::ContentManager::LoadSSFile(std::string file_name, std::string path)
{
	m_resource_manager->addData((path + file_name).c_str());
}

#pragma endregion
